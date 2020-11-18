#ifndef DEREQ_H_
#define DEREQ_H_
#include "courseLinkedList.h"
#include "degreeReq(old).h"

typedef struct DegreeReq
{
    CourseLinkedList **list;
    int size;
} DegreeReq;

extern DegreeReq *createDegreeReq();
extern void resizeDegreeReq(DegreeReq *arr);
extern void insertDegreeReq(DegreeReq *arr, CourseLinkedList *courses);
extern void printDegreeReq(DegreeReq *arr);
extern int searchCourseDegreeReq(DegreeReq *degReq, char *course);

#endif