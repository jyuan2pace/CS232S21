#include "Labyrinth.h"
#include "assert.h"
#include "string.h"

static void check_equipment(MazeCell * loc, bool * p_wand, bool * p_spell, bool * p_potion) {
	if(loc->whatsHere == Item::SPELLBOOK) {
		*p_spell = true;
	}	else if (loc->whatsHere == Item::POTION) {
		*p_potion = true;
	}	else if (loc->whatsHere == Item::WAND) {
		*p_wand = true;
	}	else {
		assert(loc->whatsHere == Item::NOTHING);
	}
}

bool isPathToFreedom(struct MazeCell* start, const std::string& moves) {
    /* TODO: Delete this comment and the remaining lines, then implement this function. */
	int n = moves.length();
    char char_array[n + 1];
    strcpy(char_array, moves.c_str());
	bool wand = false;
	bool spell = false;
	bool potion = false; 
	
	check_equipment(start, &wand, &spell, &potion);
	for(int i=0; i<n+1; i++) {
		char move = char_array[i];
		switch (move) {
			case 'N':
				if(!start->north ) {
					return false;
				} else {
					start = start -> north;
					check_equipment(start, &wand, &spell, &potion);
				}
				break;
			case 'S':
				if(!start->south ) {
					return false;
				} else {
					start = start -> south;
					check_equipment(start, &wand, &spell, &potion);
				}
				break;
			case 'W':
				if(!start->west ) {
					return false;
				} else {
					start = start -> west;
					check_equipment(start, &wand, &spell, &potion);
				}
				break;
			case 'E':
				if(!start->east ) {
					return false;
				} else {
					start = start -> east;
					check_equipment(start, &wand, &spell, &potion);
				}

				break;
			default:
				assert(move == '\0');
		}
	}
	return wand && spell && potion;
}
