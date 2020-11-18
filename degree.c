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
Function: setDegReq
--------------------------


*/
void setDegReq(Degree *deg, DegreeReq *dr)
{
    if (dr == NULL)
    {
        printf("Null deg req to put into degree\n");
        return;
    }
    deg->req = dr;
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