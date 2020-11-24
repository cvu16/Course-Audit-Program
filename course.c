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
    c->code = (char *)malloc(1000 * sizeof(char));
    strcpy(c->code, code);
    c->name = (char *)malloc(1000 * sizeof(char));
    strcpy(c->name, name);
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
    if (c == NULL)
    {
        printf("Course not found\n");
        return;
    }
    printf("%s\n", c->code);
    printf("%s\n", c->name);
    printCourseLinkedList(c->pre);
}

/*
Function : searchPrereqInCourse
----------------------------------
Search to see if this prereq in in the list for this course
Return the course pointer if it does

course: course pointer
tar: the course code to search for
*/
Course *searchPrereqInCourse(Course *course, char *tar)
{
    CourseLinkedList *res = searchCourseLinkedList(course->pre, tar);
    if (res == NULL)
    {
        return NULL;
    }
    else
        return course;
}

/*
Function : removePrereqInCourse
----------------------------------
Search to see if this prereq in in the list for this course
Remove the prereq from the course

course: course pointer
tar: the course code to search for
*/
Course *removePrereqInCourse(Course *course, char *tar)
{
    CourseLinkedList *res = removeCourseLinkedList(course->pre, tar);
    if (res == NULL)
    {
        return NULL;
    }
    else
    {
        course->pre = res;
        return course;
    }
}