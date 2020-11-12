#ifndef DEPARR_H_
#define DEPARR_H_
#include "department.h"

typedef struct DeptArrayList
{
    struct Department **list;
    int size;
} DeptArrayList;

extern DeptArrayList *createDeptArrayList();
extern void resizeDeptArrayList(DeptArrayList *list);
extern void insertDeptArrayList(DeptArrayList *list, Department *dep);
extern void printDeptArrayList(DeptArrayList *list);
extern Department *getDeptArrayList(DeptArrayList *degArr, char *name);

#endif