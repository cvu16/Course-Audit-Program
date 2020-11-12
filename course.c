#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseLinkedList.h"
#include "course.h"

/*
Function : createCourse
------------------------------------------
Takes in the codename and the full name 
of the course and return a pointer to an initialized course

code: code name of the new course
name: the full name of the new course
return: pointer to a newly allocated course

*/
Course *createCourse(char *code, char *name)
{
    Course *c = (Course *)malloc(sizeof(Course));
    c->code = code;
    c->name = name;
    c->pre = (CourseLinkedList *)malloc(sizeof(CourseLinkedList));
    return c;
}

/*
Function : addCourseReq
------------------------------------------
Add a new course codename into the LinkedList of courses required for this course 

course: pointer to the course
newReq: the new codename of the req for this course

*/
void addCourseReq(Course *course, char *newReq)
{
    insertCourseLinkedList(course->pre, newReq);
}

/*
Function : printCourse
------------------------------------------
Print out the course name and the required courses for this course

c: pointer to the course

*/
void printCourse(Course *c)
{
    printf("%s\n", c->code);
    printf("%s\n", c->name);
    printCourseLinkedList(c->pre);
}
