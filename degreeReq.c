#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseLinkedList.h"
#include "courseNode.h"
#include "degreeReq.h"

/*
Function: createDegreeReq
-------------------------------------------------
Returns a pointer to a newly allocated degree requirement bst

return: pointer to a new binary search tree
*/
DegreeReq *createDegreeReq()
{
    DegreeReq *bst = (DegreeReq *)malloc(sizeof(DegreeReq));
    return bst;
}

/*
Function: createCourseBSTNode
-------------------------------------------------
Create a new node with a given course pointer

param:
c: pointer to the course in the new node
*/
DegreeReqNode *createDegreeReqNode(CourseLinkedList *c)
{
    DegreeReqNode *cn = (DegreeReqNode *)malloc(sizeof(DegreeReqNode));
    cn->course = c;
    cn->left = NULL;
    cn->right = NULL;
    return cn;
}

/*
Function: insertDegreeReqNode
-------------------------------------------------
Insert a new course into the course binary search recursively

return: pointer to the node inserted to the bst

param:
root: current root of the bst
newCoursse: pointer to the new course being inserted

*/
DegreeReqNode *insertDegreeReqNode(DegreeReqNode *root, CourseLinkedList *newCourse)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
    {
        DegreeReqNode *newNode = createDegreeReqNode(newCourse);
        return newNode;
    }
    //Catching if newCourse is null or newCourse is empty
    if (newCourse == NULL || newCourse->first == NULL)
    {
        printf("Attempted to insert a null course linked list in degreq\n");
        return NULL;
    }
    //Take out the first code in the linkedlist and compare by that
    char *newfirst = newCourse->first->data;
    char *currfirst = root->course->first->data;
    int cmp = strcmp(newfirst, currfirst);
    /* Otherwise, recur down the tree */
    if (cmp < 0)
        root->left = insertDegreeReqNode(root->left, newCourse);
    else if (cmp > 0)
        root->right = insertDegreeReqNode(root->right, newCourse);

    /* return the (unchanged) node pointer */
    return root;
}

/*
Function: insertDegreeReq
-------------------------------------------------
Insert a new course into the course binary search tree. This function is 
essentially a wrapper function for insertCourseBSTNode

return: pointer to the node inserted to the bst

param:
bst: pointer to the bst
newCoursse: pointer to the new course being inserted

*/
DegreeReqNode *insertDegreeReq(DegreeReq *bst, CourseLinkedList *newCourse)
{
    if (bst == NULL)
    {
        printf("BST is NULL (insertion)\n");
        return NULL;
    }
    bst->root = insertDegreeReqNode(bst->root, newCourse);
}

/*
Function: printDegreeReqNode
-------------------------------------------------
Print the bst recursively using pointer to the root.
Inorder

Pit fall: skipping empty nodes

param:
root: pointer to the root

*/
void printDegreeReqNode(DegreeReqNode *root)
{
    if (root != NULL)
    {
        printDegreeReqNode(root->left);
        if (root->course->first != NULL)
        {
            printCourseLinkedList(root->course);
        }
        printDegreeReqNode(root->right);
    }
}

/*
Function: printDegreeReq
-------------------------------------------------
Print the bst. This function is essentially a wrapper function for 
printBSTNode

param:
bst: pointer to the bst

*/
void printDegreeReq(DegreeReq *bst)
{
    if (bst == NULL)
    {
        printf("This Degree Req bst doesn't exist.\n");
    }
    else if (bst->root == NULL)
    {
        printf("There is no course in this degree req bst.\n");
    }
    else if (bst != NULL)
    {
        printDegreeReqNode(bst->root);
    }
}

/*
Function: searchDegreeReq
-------------------------------------------------
Search for a node in the bst by code of course. Wrapper
function for searchCourseBSTNode

param:
bst: pointer to the bst
courseCode: code of the wanted course

*/
DegreeReqNode *searchDegreeReq(DegreeReq *bst, char *courseCode)
{
    if (bst == NULL)
    {
        printf("NULL CourseBST\n");
        return NULL;
    }
    else if (bst->root == NULL)
    {
        printf("Empty Course BST\n");
        return NULL;
    }
    else
    {
        return searchDegreeReqNode(bst->root, courseCode);
    }
}

/*
Function: searchDegreeReqNode
-------------------------------------------------
Search for a node in the bst by code of course.
Go through the bst nodes in a recursive fashion.

param:
root: pointer to the root node
courseCode: code of the wanted course

*/
DegreeReqNode *searchDegreeReqNode(DegreeReqNode *root, char *courseCode)
{
    if (root != NULL)
    {
        searchDegreeReqNode(root->left, courseCode);
        CourseLinkedList *cll = searchCourseLinkedList(root->course, courseCode);
        if (cll != NULL)
            return root;
        searchDegreeReqNode(root->right, courseCode);
    }
}

/*
Function: removeDegreeReqNode
-------------------------------------------------
Search for a node in the bst by code of course and remove it.
Go through the bst nodes in a recursive fashion.
Possible pitfall: only deleltes the prereq not the node at that prereq
=> There can be empty nodes

param:
root: pointer to the root node
courseCode: code of the wanted course

*/
DegreeReqNode *removeDegreeReqNode(DegreeReqNode *root, char *courseCode)
{
    DegreeReqNode *dn = searchDegreeReqNode(root, courseCode);
    if (dn != NULL)
    {
        dn->course = removeCourseLinkedList(dn->course, courseCode);
    }
    return dn;
}

/*
Function: removeDegreeReq
-------------------------------------------------
Wrapper function for the removeCourseBSTNode function
*/
DegreeReqNode *removeDegreeReq(DegreeReq *bst, char *courseCode)
{
    if (bst == NULL)
    {
        printf("NULL CourseBST\n");
        return NULL;
    }
    else if (bst->root == NULL)
    {
        printf("Empty Course BST\n");
        return NULL;
    }
    else
    {
        removeDegreeReqNode(bst->root, courseCode);
        return bst->root;
    }
}
