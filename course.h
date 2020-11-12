#ifndef COURSE_H_
#define COURSE_H_
#include "courseLinkedList.h"

typedef struct Course
{
    char *code;
    char *name;
    struct CourseLinkedList *pre;
} Course;

extern Course *createCourse(char *code, char *name);
extern void addCourseReq(Course *course, char *newReq);
extern void printCourse(Course *c);

#endif