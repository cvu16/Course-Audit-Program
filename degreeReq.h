#ifndef DEREQ_H_
#define DEREQ_H_
#include "courseLinkedList.h"

typedef struct DegreeReqNode
{
    CourseLinkedList *course;
    struct DegreeReqNode *left;
    struct DegreeReqNode *right;
} DegreeReqNode;

typedef struct DegreeReq
{
    struct DegreeReqNode *root;
} DegreeReq;

extern DegreeReq *createDegreeReq();
extern DegreeReqNode *createDegreeReqNode(CourseLinkedList *c);
extern DegreeReqNode *insertDegreeReqNode(DegreeReqNode *root, CourseLinkedList *newCourse);
extern DegreeReqNode *insertDegreeReq(DegreeReq *bst, CourseLinkedList *newCourse);
extern DegreeReqNode *searchDegreeReq(DegreeReq *bst, char *courseCode);
extern DegreeReqNode *searchDegreeReqNode(DegreeReqNode *root, char *courseCode);
extern DegreeReqNode *removeDegreeReqNode(DegreeReqNode *root, char *courseCode);
extern DegreeReqNode *removeDegreeReq(DegreeReq *bst, char *courseCode);
extern void printDegreeReqNode(DegreeReqNode *root);
extern void printDegreeReq(DegreeReq *bst);

#endif