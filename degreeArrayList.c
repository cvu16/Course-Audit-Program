#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "degree.h"
#include "degreeArrayList.h"

/*
Function : createDegreeArrayList
------------------------------------------
Allocate for a new Degree Array List

return: pointer to a newly allocated DegreeArrayList

*/
DegreeArrayList *createDegreeArrayList()
{
    DegreeArrayList *arr = (DegreeArrayList *)malloc(sizeof(DegreeArrayList));
    arr->size = 0;
    arr->list = (Degree **)malloc(10 * sizeof(Degree *));
    for (int i = 0; i < 10; i++)
    {
        arr->list[i] = (Degree *)malloc(sizeof(Degree));
    }
    return arr;
}

/*
Function : resizeDegreeArrayList
------------------------------------------
Increase the size of a DegreeArrayList

arr: pointer to the list

*/
void resizeDegreeArrayList(DegreeArrayList *arr)
{
    int oldSize = arr->size;
    arr->list = (Degree **)realloc(arr->list, arr->size * 2 * sizeof(Degree *));
    for (int i = oldSize; i < arr->size * 2; i++)
    {
        arr->list[i] = (Degree *)malloc(sizeof(Degree));
    }
}

/*
Function : insertDegreeArrayList
------------------------------------------
Add a new degree to the list

arr: pointer to the list
deg: pointer to the new degree

*/
void insertDegreeArrayList(DegreeArrayList *arr, Degree *deg)
{
    if (arr == NULL)
    {
        printf("Degree ArrayList is NULL\n");
        return;
    }
    if (arr->list == NULL && arr->size == 0 || deg == NULL)
    {
        printf("Something is NULL\n");
        return;
    }
    if ((arr->size) % 10 == 0 && arr->size != 0)
        resizeDegreeArrayList(arr);
    arr->list[arr->size] = deg;
    arr->size++;
}

/*
Function : printDegreeArrayList
------------------------------------------
Print the DegreeArrayList

arr: pointer to the DegreeArrayList

*/
void printDegreeArrayList(DegreeArrayList *arr)
{
    if (arr == NULL)
    {
        printf("DAL is Null");
        return;
    }
    if (arr->list == NULL && arr->size == 0)
    {
        printf("Something is NULL\n");
        return;
    }
    for (int i = 0; i < arr->size; i++)
    {
        printDeg(arr->list[i]);
    }
}

/*
Function : getDegreeArrayList
------------------------------------------
Search in the degreeArrayList of the degree 

degArr: pointer to the degree list
name: name of the degree wanted

*/
Degree *getDegreeArrayList(DegreeArrayList *degArr, char *name)
{
    if (degArr->list == NULL || degArr->size == 0)
    {
        //printf("DAL is Null or Empty\n");
        return NULL;
    }
    Degree **array = degArr->list;
    for (int i = 0; i < degArr->size; i++)
    {
        if (strcmp(array[i]->name, name) == 0)
        {
            return array[i];
        }
    }
    //printf("NOT FOUND\n");
    return NULL;
}