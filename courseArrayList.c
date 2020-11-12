#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "courseArrayList.h"

/*
Function : createCourseArrayList
------------------------------------------
Return a pointer a newly allocated course array list

return: a new course array list

*/
CourseArrayList *createCourseArrayList()
{
    CourseArrayList *arr = (CourseArrayList *)malloc(sizeof(CourseArrayList));
    arr->size = 0;
    arr->list = (Course **)malloc(10 * sizeof(Course *));
    for (int i = 0; i < 10; i++)
    {
        arr->list[i] = (Course *)malloc(sizeof(Course));
    }
    return arr;
}

/*
Function : resizeCourseArrayList
------------------------------------------
Resize the course array list by doubling the old size

arr: the array list to be resized

*/
void resizeCourseArrayList(CourseArrayList *arr)
{
    int oldSize = arr->size;
    arr->list = (Course **)realloc(arr->list, arr->size * 2 * sizeof(Course *));
    for (int i = oldSize; i < arr->size * 2; i++)
    {
        arr->list[i] = (Course *)malloc(sizeof(Course));
    }
}

/*
Function : insertCourseArrayList
------------------------------------------
Add a new course into the course array list pointed to

arr: the course array list pointed to
c: the pointer to the new course

*/
void insertCourseArrayList(CourseArrayList *arr, Course *c)
{
    if (arr == NULL)
    {
        printf("Course ArrayList is NULL\n");
        return;
    }
    if (arr->list == NULL && arr->size == 0 || c == NULL)
    {
        printf("Something is NULL\n");
        return;
    }
    if ((arr->size) % 10 == 0 && arr->size != 0)
        resizeCourseArrayList(arr);
    arr->list[arr->size] = c;
    arr->size++;
}

/*
Function : printCourseArrayList
------------------------------------------
Print the course array list

arr: pointer to the array list to be printed

*/
void printCourseArrayList(CourseArrayList *arr)
{
    if (arr == NULL)
    {
        printf("CRL is Null");
        return;
    }
    if (arr->list == NULL && arr->size == 0)
    {
        printf("Something is NULL\n");
        return;
    }
    for (int i = 0; i < arr->size; i++)
    {
        printCourse(arr->list[i]);
    }
}

/*
Function : getCourseArrayList
------------------------------------------
Takes in the code name of a course and return the course
or null if NOT FOUND from the array list

degArr: the array list of courses
name: code name of the course wanted

*/
Course *getCourseArrayList(CourseArrayList *degArr, char *code)
{
    if (degArr->list == NULL || degArr->size == 0)
    {
        printf("DAL is Null or Empty\n");
        return NULL;
    }
    Course **array = degArr->list;
    for (int i = 0; i < degArr->size; i++)
    {
        if (strcmp(array[i]->code, code) == 0)
        {
            return array[i];
        }
    }
    printf("NOT FOUND\n");
    return NULL;
}

/*
Function : checkCourseReq
------------------------------------------
Print out the courses to take after taking a course

degArr: pointer to the array list
code: the code name of the course taken

*/
void checkCourseReq(CourseArrayList *degArr, char *code)
{
    if (degArr->list == NULL || degArr->size == 0)
    {
        printf("DAL is Null or Empty\n");
    }
    Course **array = degArr->list;
    for (int i = 0; i < degArr->size; i++)
    {
        if (searchCourseLinkedList(array[i]->pre, code) == 1)
        {
            printf("%s,", array[i]->code);
        }
    }
}