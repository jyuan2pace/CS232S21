#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	char name[20];
	int id;
};

struct student * student_allocator(char * name, int id) {
	struct student * p_stu = (struct student*) malloc(sizeof(struct student));
	strcpy(p_stu->name, name);
	p_stu->id = id;	
}

void student_deallocator(struct student *p_stu) {
	free(p_stu);
}

int main() {
	struct student * stud;
	stud = student_allocator("Jon Doe", 1);
	printf("student's name is %s, and id is %d\n", stud->name, stud->id);
	student_deallocator(stud);
	return 0;
}
