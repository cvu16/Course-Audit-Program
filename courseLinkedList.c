#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseNode.h"
#include "courseLinkedList.h"

/*
Function : createCourseLinkedList
------------------------------------------
Create a new course linkedlist

return: pointer to the created course linked list

*/
CourseLinkedList *createCourseLinkedList()
{
    CourseLinkedList *list = (CourseLinkedList *)malloc(sizeof(CourseLinkedList));
    list->first = NULL;
    return list;
}

/*
Function : printCourseLinkedList
------------------------------------------
Add a new course codename into the LinkedList of courses required for this course 

list: the pointer to the course linked list to be printed

*/
void printCourseLinkedList(CourseLinkedList *list)
{
    if (list->first == NULL)
    {
        printf("(There is no prerequisite)\n");
        return;
    }
    CourseNode *first = list->first;
    if (first->next != NULL)
    {
        printf("OR ");
        while (first != NULL)
        {
            printNode(first);
            first = first->next;
        }
        printf("\n");
        return;
    }
    printNode(first);
    printf("\n");
}

/*
Function : insertCourseLinkedList
------------------------------------------
Add a new course with code name into the LinkedList of courses 

list: pointer to the courseLinkedList
newData: the code name of the new course

*/
void insertCourseLinkedList(CourseLinkedList *list, char *newData)
{
    if (list->first == NULL)
    {
        CourseNode *cn = createNode(newData, NULL, NULL);
        list->first = cn;
        return;
    }
    CourseNode *curr = list->first;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    CourseNode *new = createNode(newData, curr, NULL);
    curr->next = new;
}

/*
Function : searchCourseLinkedList
------------------------------------------
Search in the linked list to find the code name of the course

list: pointer to the course linked list
tar: the course code name to be searcher for

*/
CourseLinkedList *searchCourseLinkedList(CourseLinkedList *list, char *tar)
{
    if (list->first == NULL)
    {
        //printf("Searching NULL LinkedList\n");
        return NULL;
    }
    if (list->first == NULL)
    {
        //printf("Searching empty LinkedList\n");
        return NULL;
    }
    CourseNode *curr = list->first;
    while (curr != NULL)
    {
        if (strcmp(curr->data, tar) == 0)
            return list;
        else
            curr = curr->next;
    }
    //printf("Search CLL not found\n");
    return NULL;
}

/*
Function : removeCourseLinkedList
------------------------------------------
Search in the linked list to find the code name of the course and remove it

list: pointer to the course linked list
tar: the course code name to be searcher for

*/
CourseLinkedList *removeCourseLinkedList(CourseLinkedList *list, char *tar)
{
    if (list->first == NULL)
    {
        printf("Removing empty LinkedList\n");
        return NULL;
    }
    CourseNode *curr = list->first;

    //Edge case: removing the first node
    if (strcmp(curr->data, tar) == 0)
    {
        list->first = curr->next;
        if (list->first != NULL)
            list->first->prev = NULL;
        free(curr);
        return list;
    }
    while (curr != NULL)
    {
        if (strcmp(curr->data, tar) == 0)
        {
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
            }
            else
            {
                curr->prev->next = NULL;
            }
            free(curr);
            return list;
        }
        else
            curr = curr->next;
    }
    return NULL;
}