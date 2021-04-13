#pragma once

#include "Labyrinth.h"
#include <string>

/**
 * Returns a maze of size numRows x numCols, specifically tailored to
 * the given name.
 *
 * We've implemented this function for you. You don't need to write it
 * yourself.
 *
 * Please don't make any changes to this function - we'll be using our
 * reference version when testing your code, and it would be a shame if
 * the maze you solved wasn't the maze we wanted you to solve!
 */
MazeCell* mazeFor(const std::string& name);

/**
 * Returns a Twisty Maze with the specified number of nodes.
 *
 * Please don't make any changes to this function - we'll be using our
 * reference version when testing your code, and it would be a shame if
 * the maze you solved wasn't the maze we wanted you to solve!
 */
MazeCell* twistyMazeFor(const std::string& name);
