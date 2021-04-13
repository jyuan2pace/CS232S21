/******************************************************
* File: main.c
*
* Driver file
*
* Change Log:
* 12/02/2006, By Jun Yuan, created for CS101, HUST, China
* 01/05/2016, By Jun Yuan-Murray, modified for BCS230, Farmingdale, NY
* 02/11/2017, By Jun Yuan-Murray, modified for BCS230, Farmingdale, NY
* 02/18/2017, By Jun Yuan-Murray, modified for BCS230, Farmingdale, NY
* 04/16/2019, By Jun Yuan-Murray, modified for CS232, Pace, NY
******************************************************/

#include <assert.h>
#include "asciimation.h"
#include <stdio.h>
#include <stdlib.h>
void get_valid_option(int *n) {
	int r = scanf("%d", n);
	while (r!=1 || *n<1 || *n>3) {
		printf("\nPlease enter a number from 1 to 3: ");
		r = scanf("%d", n);
	}

}

int main() {
	int option;
		
	char path[4096];
	int fps;

	printf("Please input your ascii data file path\n");
	scanf("%s", path);

	printf("How many frames per second?\n");
	scanf("%d", &fps);

	system("@cls||clear");
	asciimation_t * ascm = asciimation_new(path, fps);
	do {
		printf ( "+-------------------------------------------+\n");
		printf ( "|                                           |\n");
		printf ( "| Console users love ascii art!!            |\n");
		printf ( "|                                           |\n");
		printf ( "| 1- Play the ascii animation once          |\n");
		printf ( "| 2- Play the ascii animation in reverse    |\n");
		printf ( "| 3- Exit                                   |\n");
		printf ( "+-------------------------------------------+\n");

		printf("\n Please enter your option:");
		get_valid_option(&option);

		switch (option) {
		case 1: {
			asciimation_play(ascm);
			break;
		}
		case 2: {
			asciimation_reverse(ascm);	
			break;
		}
		case 3: {
			asciimation_delete(ascm);
			return 0;
		}
		default:
			return 1;//impossible
		}
		printf("[press any key to continue]\n");
		system("@cls||clear");
	} while (1);
	
}
