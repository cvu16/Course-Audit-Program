#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "department.h"
#include "deptArrayList.h"

DeptArrayList *createDeptArrayList()
{
    DeptArrayList *arr = (DeptArrayList *)malloc(sizeof(DeptArrayList));
    arr->size = 0;
    arr->list = (Department **)malloc(10 * sizeof(Department *));
    for (int i = 0; i < 10; i++)
    {
        arr->list[i] = (Department *)malloc(sizeof(Department));
    }
    return arr;
}

void resizeDeptArrayList(DeptArrayList *arr)
{
    int oldSize = arr->size;
    arr->list = (Department **)realloc(arr->list, arr->size * 2 * sizeof(Department *));
    for (int i = oldSize; i < arr->size * 2; i++)
    {
        arr->list[i] = (Department *)malloc(sizeof(Department));
    }
}

void insertDeptArrayList(DeptArrayList *arr, Department *dep)
{
    if (arr == NULL)
    {
        printf("Degree ArrayList is NULL\n");
        return;
    }
    if (arr->list == NULL && arr->size == 0 || dep == NULL)
    {
        printf("Something is NULL\n");
        return;
    }
    if ((arr->size) % 10 == 0 && arr->size != 0)
        resizeDeptArrayList(arr);
    arr->list[arr->size] = dep;
    arr->size++;
}

void printDeptArrayList(DeptArrayList *arr)
{
    if (arr == NULL)
    {
        printf("DeptAL is Null");
        return;
    }
    if (arr->list == NULL && arr->size == 0)
    {
        printf("Something is NULL\n");
        return;
    }
    for (int i = 0; i < arr->size; i++)
    {
        printDept(arr->list[i]);
    }
}

Department *getDeptArrayList(DeptArrayList *degArr, char *name)
{
    if (degArr->list == NULL || degArr->size == 0)
    {
        printf("DAL is Null or Empty\n");
        return NULL;
    }
    Department **array = degArr->list;
    for (int i = 0; i < degArr->size; i++)
    {
        if (strcmp(array[i]->name, name) == 0)
        {
            return array[i];
        }
    }
    printf("NOT FOUND\n");
    return NULL;
}