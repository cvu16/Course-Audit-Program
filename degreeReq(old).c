#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseLinkedList.h"
#include "degreeReq(old).h"

/*
Function : createDegreeReq
------------------------------------------
Create a new DegreeReq

return: pointer to a new DegreeReq

*/
DegreeReq *createDegreeReq()
{
    DegreeReq *degReq = (DegreeReq *)malloc(sizeof(DegreeReq));
    degReq->list = (CourseLinkedList **)malloc(10 * sizeof(CourseLinkedList *));
    degReq->size = 0;
    for (int i = 0; i < 10; i++)
    {
        degReq->list[i] = createCourseLinkedList();
    }
    return degReq;
}

/*
Function : resizeDegreeReq
------------------------------------------
Increase the size of a degree req

arr: pointer to a DegreeReq

*/
void resizeDegreeReq(DegreeReq *arr)
{
    int oldSize = arr->size;
    arr->list = (CourseLinkedList **)realloc(arr->list, arr->size * 2 * sizeof(CourseLinkedList *));
    for (int i = oldSize; i < arr->size; i++)
    {
        arr->list[i] = (CourseLinkedList *)malloc(sizeof(CourseLinkedList));
    }
}
/*
Function : insertDegreeReq
------------------------------------------
Add a new linked list to the Degree Req

arr: pointer to the list
courses: pointer the the requirement list

*/
void insertDegreeReq(DegreeReq *arr, CourseLinkedList *courses)
{
    if (arr == NULL)
    {
        printf("Degree ArrayList is NULL\n");
        return;
    }
    if (arr->list == NULL || courses == NULL)
    {
        printf("CLL in DegReq is NULL\n");
        return;
    }
    if ((arr->size) % 10 == 0 && arr->size != 0)
        resizeDegreeReq(arr);
    if (arr->size == 0)
    {
        arr->list[0] = courses;
        arr->size++;
        return;
    }
    else
    {
        arr->list[arr->size] = courses;
        arr->size++;
        return;
    }
}

/*
Function : printDegreeReq
------------------------------------------
Print the DegreeReq

arr: pointer to the DegreeReq

*/
void printDegreeReq(DegreeReq *arr)
{
    if (arr == NULL)
    {
        printf("DR is Null");
        return;
    }
    if (arr->list == NULL && arr->size == 0)
    {
        printf("Something is NULL\n");
        return;
    }
    for (int i = 0; i < arr->size; i++)
    {
        printCourseLinkedList(arr->list[i]);
    }
}

//Search and return the requirement by title of the course
//if found return the index of the requirement(CLL) if not return -1
int searchCourseDegreeReq(DegreeReq *degReq, char *course)
{
    if (degReq->size == 0)
    {
        return -1;
    }
    for (int i = 0; i < degReq->size; i++)
    {
        int search = searchCourseLinkedList(degReq->list[i], course);
        if (search == -1)
        {
            printf("Something in DegreeReq's CourseLinkedList is null\n");
            return -1;
        }
        else if (search == 1)
            return i;
    }
    return -1;
}
