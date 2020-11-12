#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseLinkedList.h"
#include "degreeReq.h"
#include "degree.h"

/*
Function : createDeg
------------------------------------------
Create a new Degree

name: name of the newly created degree
return: pointer to the newly created Degree

*/
Degree *createDeg(char *name)
{
    Degree *deg = (Degree *)malloc(sizeof(Degree));
    deg->name = name;
    deg->dept = NULL;
    deg->req = createDegreeReq();
}

/*
Function : addCourseDeg
------------------------------------------
Add a new course into the DegreeReq

deg: pointer to the degree
newCourse: the new course to be added
or: the prerequisite for this newCourse, if nothing then ""

*/
void addCourseDeg(Degree *deg, char *newCourse, char * or)
{
    int search = searchCourseDegreeReq(deg->req, or);
    DegreeReq *degreeReq = deg->req;
    if (degreeReq == NULL)
    {
        printf("Something is NULL\n");
        return;
    }
    if (search != -1)
    {
        insertCourseLinkedList(degreeReq->list[search], newCourse);
    }
    else
    {
        CourseLinkedList *cll = createCourseLinkedList();
        insertCourseLinkedList(cll, newCourse);
        insertDegreeReq(deg->req, cll);
    }
}

/*
Function : setDeptDeg
------------------------------------------
Set the department of the degree

deg: pointer to the degree
dept: pointer to the department

*/
void setDeptDeg(Degree *deg, char *dept)
{
    deg->dept = dept;
}

/*
Function : printDeg
------------------------------------------
Print the degree pointed to
deg: the pointer to the degree

*/
void printDeg(Degree *deg)
{
    if (deg->name != NULL)
        printf("%s\n", deg->name);
    if (deg->dept != NULL)
        printf("%s\n", deg->dept);
    printDegreeReq(deg->req);
}