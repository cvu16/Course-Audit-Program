#ifndef DEG_H_
#define DEG_H_
#include "courseLinkedList.h"
#include "degreeReq.h"

typedef struct Degree
{
    char *name;
    char *dept;
    struct DegreeReq *req;
} Degree;

extern Degree *createDeg(char *name);
extern void setDegReq(Degree *deg, DegreeReq *dr);
extern void setDeptDeg(Degree *deg, char *dept);
extern void printDeg(Degree *deg);

#endif