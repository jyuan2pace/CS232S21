#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>

int main() {
    /* Generate the maze.
     *
     * Note: Don't set a breakpoint on this line. Otherwise, you'll see startLocation before
     * it's been initialized.
     */
  	std::string name, pathOutOfNormalMaze;
	std::getline (std::cin, name);
	std::getline (std::cin, pathOutOfNormalMaze);

    MazeCell* startLocation = mazeFor(name);
    
    /* Set a breakpoint here to explore your maze! */
    if (isPathToFreedom(startLocation, pathOutOfNormalMaze)) {
        std::cout << "Congratulations! You've found a way out of your labyrinth." << std::endl;
    } else {
        std::cout << "Sorry, but you're still stuck in your labyrinth." << std::endl;
    }
    
    return 0;
}
