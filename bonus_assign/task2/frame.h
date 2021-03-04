/******************************************************
* File: frame.h
*
* This is the header file frame.c
*
******************************************************/
//This is the header guide.
#ifndef FRAME_H_232
#define FRAME_H_232
typedef struct frame_t {
	int rep_counter;
	int id;
	char * content;
} frame_t;

struct frame_t * frame_new(char * pathnam, int id);
void frame_delete(struct frame_t * f);
char* frame_get_content (struct frame_t *f);
int frame_get_rep_counter(struct frame_t * f);
int frame_get_id(struct frame_t *f);
#endif
