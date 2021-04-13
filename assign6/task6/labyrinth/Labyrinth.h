#pragma once
#include <string>

/**
 * Type representing an item in the maze.
 */
enum class Item {
    NOTHING, SPELLBOOK, POTION, WAND
};

/**
 * Type representing a cell in the maze.
 */
struct MazeCell {
    Item whatsHere; // Which item, if any, is present.

    MazeCell* north;
    MazeCell* south;
    MazeCell* east;
    MazeCell* west;
};

/**
 * Given a location in a maze, returns whether the given sequence of
 * steps will let you escape the maze.
 *
 * To escape the maze, you need to find the Potion, the Spellbook, and
 * the Wand. You can only take steps in the four cardinal directions,
 * and you can't move in directions that don't exist in the maze.
 */
bool isPathToFreedom(MazeCell* start, const std::string& moves);
