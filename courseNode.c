#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseNode.h"

/*
Function : createNode
------------------------------------------
Return a newly allocated node

d: name of the node
p: the previous node
nx: the next node

*/
CourseNode *createNode(char *d, CourseNode *p, CourseNode *nx)
{
    CourseNode *np = (CourseNode *)malloc(sizeof(CourseNode));
    np->data = (char *)malloc(1000 * sizeof(char));
    strcpy(np->data, d);
    if (p != NULL)
        np->prev = p;
    else
        np->prev = NULL;
    if (nx != NULL)
        np->next = nx;
    else
        np->next = NULL;
    return np;
}

/*
Function : printNode
------------------------------------------
Print the pointed node

n: pointer to the node to be printed

*/
void printNode(CourseNode *n)
{
    printf("%s ", n->data);
}
