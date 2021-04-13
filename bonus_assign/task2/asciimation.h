/******************************************************
* File: asciimation.h
*
* This is the header file for asciimation.c
*
******************************************************/
#ifndef ASCIIMATION_H_232
#define ASCIIMATION_H_232
#include "vector.h"
#include "frame.h"
typedef struct asciimation_t {
	vector_t * frames; //maintains a vector of frame pointers. each points to a frame
	int frames_per_second;//how fast do you play the asciimation?	
} asciimation_t;

		
asciimation_t * asciimation_new(char *, int);
void asciimation_delete(asciimation_t *);
void asciimation_play(asciimation_t *);
void asciimation_reverse(asciimation_t *);

//the following are not requried
//	void asciimation_loop();
//	void asciimation_deleteFrame(int);
//	void asciimation_insertFrame(Frame);
//	void asciimation_save();

#endif
