#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>

/* Change this constant to contain your name.
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
int main() {
    /* Generate the maze.
     *
     * Note: Don't set a breakpoint on this line. Otherwise, you'll see startLocation before
     * it's been initialized.
     */
  	std::string name, pathOutOfTwistyMaze;
	std::getline (std::cin, name);
	std::getline (std::cin, pathOutOfTwistyMaze);

   
    
    /* Generate the twisty maze.
     *
     * Note: Don't set a breakpoint on this line. Otherwise, you'll see twistyStartLocation before
     * it's been initialized.
     */
    MazeCell* twistyStartLocation = twistyMazeFor(name);
    
    /* Set a breakpoint here to explore your twisty maze! */
    
    if (isPathToFreedom(twistyStartLocation, pathOutOfTwistyMaze)) {
        std::cout << "Congratulations! You've found a way out of your twisty labyrinth." << std::endl;
    } else {
        std::cout << "Sorry, but you're still stuck in your twisty labyrinth." << std::endl;
    }
    
    return 0;
}
