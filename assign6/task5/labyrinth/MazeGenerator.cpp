#include "MazeGenerator.h"
#include <utility>
#include <random>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
namespace {
    template <typename T> using Grid = vector<vector<T>>;
    
    /* Creates a blank grid maze of the given size. */
    template <typename T> Grid<T> blankMaze(size_t numRows, size_t numCols, const T& value = T()) {
        return Grid<T>(numRows, vector<T>(numCols, value));
    }
    
    /* Row / column count. */
    template <typename T> size_t numRows(const Grid<T>& grid) {
        return grid.size();
    }
    template <typename T> size_t numCols(const Grid<T>& grid) {
        return grid.empty()? 0 : grid[0].size();
    }

    /* Type representing a possible edge in a maze. Two MazeCells are each
     * included here, along with the fields that would link them.
     */
    struct EdgeBuilder {
        /* Which two edges to link. */
        MazeCell* first;
        MazeCell* second;

        /* How to link them. */
        MazeCell* MazeCell::* firstField;
        MazeCell* MazeCell::* secondField;
    };

    /* Generates a random number in the specified range. We use this instead of
     * std::uniform_int_distribution because std::uniform_int_distribution is
     * not cross-platform compatible.
     */
    size_t mtRandomBetween(size_t low, size_t high, mt19937& generator) {
        return low + generator() % (high - low + 1);
    }

    /* Generates a random real number between 0 and 1. We use this instead of
     * std::uniform_real_distribution because std::uniform_real_distribution is
     * not cross-platform compatible.
     */
    double mtRandomProbability(mt19937& generator) {
        while (true) {
            uint32_t value = generator();
            uint32_t max   = numeric_limits<decltype(value)>::max();

            if (value != max) {
                return double(value) / max;
            }
        }
    }

    /* Returns all possible edges that could appear in a grid maze. */
    vector<EdgeBuilder> allPossibleEdgesFor(const Grid<MazeCell*>& maze) {
        vector<EdgeBuilder> result;
        for (size_t row = 0; row < numRows(maze); row++) {
            for (size_t col = 0; col < numCols(maze); col++) {
                if (row + 1 < numRows(maze)) {
                    result.push_back({ maze[row][col], maze[row + 1][col], &MazeCell::south, &MazeCell::north });
                }
                if (col + 1 < numCols(maze)) {
                    result.push_back({ maze[row][col], maze[row][col + 1], &MazeCell::east, &MazeCell::west });
                }
            }
        }
        return result;
    }

    /* Union-find FIND operation. */
    MazeCell* repFor(const map<MazeCell*, MazeCell*>& reps, MazeCell* cell) {
        while (reps.at(cell) != cell) {
            cell = reps.at(cell);
        }
        return cell;
    }

    /* Shuffles the edges using the Fischer-Yates shuffle. We provide our own
     * implementation because the std::shuffle implementations on Windows, Mac,
     * and Linux are not guaranteed to work in the same way.
     */
    void shuffleEdges(vector<EdgeBuilder>& edges, mt19937& generator) {
        for (size_t i = 0; i < edges.size(); i++) {
            size_t j = mtRandomBetween(i, edges.size() - 1, generator);
            swap(edges[i], edges[j]);
        }
    }

    /* Creates a random maze of the given size using a randomized Kruskal's
     * algorithm. Edges are shuffled and added back in one at a time, provided
     * that each insertion links two disconnected regions.
     */
    Grid<MazeCell*> makeMaze(size_t numRows, size_t numCols, mt19937& generator) {
        auto maze = blankMaze<MazeCell*>(numRows, numCols);
        for (size_t row = 0; row < numRows; row++) {
            for (size_t col = 0; col < numCols; col++) {
                maze[row][col] = new MazeCell();
            }
        }

        auto edges = allPossibleEdgesFor(maze);
        shuffleEdges(edges, generator);

        /* Union-find structure, done without path compression because N is small. */
        map<MazeCell*, MazeCell*> representatives;
        for (size_t row = 0; row < numRows; row++) {
            for (size_t col = 0; col < numCols; col++) {
                auto* elem = maze[row][col];
                representatives[elem] = elem;
            }
        }

        /* Run a randomized Kruskal's algorithm to build the maze. */
        size_t edgesLeft = numRows * numCols - 1;
        for (size_t i = 0; edgesLeft > 0 && i < edges.size(); i++) {
            auto edge = edges[i];

            /* See if they're linked already. */
            auto* rep1 = repFor(representatives, edge.first);
            auto* rep2 = repFor(representatives, edge.second);

            /* If not, link them. */
            if (rep1 != rep2) {
                representatives[rep1] = rep2;

                edge.first->*edge.firstField   = edge.second;
                edge.second->*edge.secondField = edge.first;

                edgesLeft--;
            }
        }
        if (edgesLeft != 0) abort(); // Internal error!

        return maze;
    }

    /* Clears all the links between the given group of nodes. */
    void clearGraph(vector<MazeCell*>& nodes) {
        for (auto* node: nodes) {
            *node = MazeCell();
        }
    }

    /* Returns a random unassigned link from the given node, or nullptr if
     * they are all assigned.
     */
    MazeCell* MazeCell::* randomFreePortOf(MazeCell* cell, mt19937& generator) {
        vector<MazeCell* MazeCell::*> ports;
        if (cell->east  == nullptr) ports.push_back(&MazeCell::east);
        if (cell->west  == nullptr) ports.push_back(&MazeCell::west);
        if (cell->north == nullptr) ports.push_back(&MazeCell::north);
        if (cell->south == nullptr) ports.push_back(&MazeCell::south);
        if (ports.empty()) return nullptr;

        int port = mtRandomBetween(0, ports.size() - 1, generator);
        return ports[port];
    }

    /* Use a variation of the Erdos-Renyi random graph model. We set the
     * probability of any pair of nodes being connected to be ln(n) / n,
     * then artificially constrain the graph so that no node has degree
     * four or more. We generate mazes this way until we find one that's
     * conencted.
     */
    bool erdosRenyiLink(vector<MazeCell*>& nodes, mt19937& generator) {
        /* High probability that everything is connected. */
        double threshold = log(nodes.size()) / nodes.size();

        for (size_t i = 0; i < nodes.size(); i++) {
            for (size_t j = i + 1; j < nodes.size(); j++) {
                if (mtRandomProbability(generator) <= threshold) {
                    auto iLink = randomFreePortOf(nodes[i], generator);
                    auto jLink = randomFreePortOf(nodes[j], generator);

                    /* Oops, no free links. */
                    if (iLink == nullptr || jLink == nullptr) {
                        return false;
                    }

                    nodes[i]->*iLink = nodes[j];
                    nodes[j]->*jLink = nodes[i];
                }
            }
        }

        return true;
    }

    /* Returns whether the given maze is fully connected. */
    bool isConnected(const vector<MazeCell*>& maze) {
        unordered_set<MazeCell*> visited;
        queue<MazeCell*> frontier;
        
        frontier.push(maze[0]);

        while (!frontier.empty()) {
            auto* curr = frontier.front();
            frontier.pop();

            if (!visited.count(curr)) {
                visited.insert(curr);

                if (curr->east  != nullptr) frontier.push(curr->east);
                if (curr->west  != nullptr) frontier.push(curr->west);
                if (curr->north != nullptr) frontier.push(curr->north);
                if (curr->south != nullptr) frontier.push(curr->south);
            }
        }

        return visited.size() == maze.size();
    }

    /* Generates a random twisty maze. This works by repeatedly generating
     * random graphs until a connected one is found.
     */
    vector<MazeCell*> makeTwistyMaze(size_t numNodes, mt19937& generator) {
        vector<MazeCell*> result;
        for (size_t i = 0; i < numNodes; i++) {
            result.push_back(new MazeCell());
        }

        /* Keep generating mazes until we get a connected one. */
        do {
            clearGraph(result);
        } while (!erdosRenyiLink(result, generator) || !isConnected(result));

        return result;
    }

    /* Returns if two nodes are adjacent. */
    bool areAdjacent(MazeCell* first, MazeCell* second) {
        return first->east  == second ||
               first->west  == second ||
               first->north == second ||
               first->south == second;
    }

    /* Uses the Floyd-Warshall algorithm to compute the shortest paths between all
     * pairs of nodes in the maze. The result is a table where table[i][j] is the
     * shortest path distance between maze[i] and maze[j].
     */
    Grid<int> allPairsShortestPaths(const vector<MazeCell*>& maze) {
        /* Floyd-Warshall algorithm. Fill the grid with "infinity" values. */
        Grid<int> result = blankMaze<int>(maze.size(), maze.size(), maze.size() + 1);

        /* Set distances of nodes to themselves at 0. */
        for (size_t i = 0; i < maze.size(); i++) {
            result[i][i] = 0;
        }

        /* Set distances of edges to 1. */
        for (size_t i = 0; i < maze.size(); i++) {
            for (size_t j = 0; j < maze.size(); j++) {
                if (areAdjacent(maze[i], maze[j])) {
                    result[i][j] = 1;
                }
            }
        }

        /* Dynamic programming step. Keep expanding paths by allowing for paths
         * between nodes.
         */
        for (size_t i = 0; i < maze.size(); i++) {
            Grid<int> next = blankMaze<int>(numRows(result), numCols(result));
            for (size_t j = 0; j < maze.size(); j++) {
                for (size_t k = 0; k < maze.size(); k++) {
                    next[j][k] = min(result[j][k], result[j][i] + result[i][k]);
                }
            }
            result = next;
        }

        return result;
    }

    /* Given a list of distinct nodes, returns the "score" for their distances,
     * which is a sequence of numbers representing pairwise distances in sorted
     * order.
     */
    vector<size_t> scoreOf(const vector<size_t>& nodes, const Grid<int>& distances) {
        vector<size_t> result;

        for (size_t i = 0; i < nodes.size(); i++) {
            for (size_t j = i + 1; j < nodes.size(); j++) {
                result.push_back(distances[nodes[i]][nodes[j]]);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

    /* Given a grid, returns a combination of four nodes whose overall score
     * (sorted list of pairwise distances) is as large as possible in a
     * lexicographical sense.
     */
    vector<size_t> remoteLocationsIn(const Grid<int>& distances) {
        vector<size_t> result = {0, 1, 2, 3};

        /* We could do this recursively, but since it's "only" four loops
         * we'll just do that instead. :-)
         */
        for (size_t i = 0; i < numRows(distances); i++) {
            for (size_t j = i + 1; j < numRows(distances); j++) {
                for (size_t k = j + 1; k < numRows(distances); k++) {
                    for (size_t l = k + 1; l < numRows(distances); l++) {
                        vector<size_t> curr = { i, j, k, l };
                        if (scoreOf(curr, distances) > scoreOf(result, distances)) {
                            result = curr;
                        }
                    }
                }
            }
        }

        return result;
    }
    
    
    /* Simple rolling hash. Stolen shameless from StanfordCPPLib, maintained by a collection
     * of talented folks at Stanford University.
     */
    const int HASH_SEED = 5381;               // Starting point for first cycle
    const int HASH_MULTIPLIER = 33;           // Multiplier for each cycle
    const int HASH_MASK = unsigned(-1) >> 1;  // All 1 bits except the sign
    
    int hashCode(size_t value) {
        return value & HASH_MASK;
    }
    
    int hashCode(const string& str) {
        unsigned hash = HASH_SEED;
        for (size_t i = 0; i < str.length(); i++) {
            hash = HASH_MULTIPLIER * hash + str[i];
        }
        return hashCode(hash);
    }
    
    /*
     * Computes a composite hash code from a list of multiple values.
     * The components are scaled up so as to spread out the range of values
     * and reduce collisions.
     */
    template <typename T1, typename T2, typename... Others>
    int hashCode(T1&& first, T2&& second, Others&&... remaining) {
        int result = HASH_SEED;

        /* Compute the hash code for the last n - 1 arguments. */
        result += hashCode(std::forward<T2>(second), std::forward<Others>(remaining)...);

        /* Update the hash to factor in the hash of the first element. */
        result *= HASH_MULTIPLIER;
        result += hashCode(std::forward<T1>(first));

        /* Hash the resulting integer to mask off any unneeded bits. */
        return hashCode(result);
    }
}

const size_t kNumRows = 4;
const size_t kNumCols = 4;

MazeCell* mazeFor(const string& name) {
    /* Seed a generator using the provided seed. From this point forward, only
     * use random numbers from this source.
     */
    mt19937 generator(hashCode(name, kNumRows, kNumCols));
    auto maze = makeMaze(kNumRows, kNumCols, generator);

    /* Place the items and start locations far away from one another. */
    vector<MazeCell*> linearMaze;
    for (size_t i = 0; i < numRows(maze); i++) {
        for (size_t j = 0; j < numCols(maze); j++) {
            linearMaze.push_back(maze[i][j]);
        }
    }


    auto distances = allPairsShortestPaths(linearMaze);
    auto locations = remoteLocationsIn(distances);

    /* Place the items. */
    linearMaze[locations[1]]->whatsHere = Item::SPELLBOOK;
    linearMaze[locations[2]]->whatsHere = Item::POTION;
    linearMaze[locations[3]]->whatsHere = Item::WAND;

    /* We begin in position 0. */
    return linearMaze[locations[0]];
}

const size_t kNumTwistyRooms = 12;

MazeCell* twistyMazeFor(const string& name) {
    /* Seed a generator using the provided seed. From this point forward, only
     * use random numbers from this source.
     */
    mt19937 generator(hashCode(name, kNumTwistyRooms));
    auto maze = makeTwistyMaze(kNumTwistyRooms, generator);

    /* Find the distances between all pairs of nodes. */
    auto distances = allPairsShortestPaths(maze);

    /* Select a 4-tuple maximizing the minimum distances between points,
     * and use that as our item/start locations.
     */
    auto locations = remoteLocationsIn(distances);

    /* Place the items there. */
    maze[locations[1]]->whatsHere = Item::SPELLBOOK;
    maze[locations[2]]->whatsHere = Item::POTION;
    maze[locations[3]]->whatsHere = Item::WAND;

    return maze[locations[0]];
}
