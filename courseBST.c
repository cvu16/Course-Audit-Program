#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "courseBST.h"

/*
Function: createCourseBST
-------------------------------------------------
Returns a pointer to a newly allocated course binary search tree

return: pointer to a new binary search tree
*/
CourseBST *createCourseBST()
{
    CourseBST *bst = (CourseBST *)malloc(sizeof(CourseBST));
    return bst;
}

/*
Function: createCourseBSTNode
-------------------------------------------------
Create a new node with a given course pointer

param:
c: pointer to the course in the new node
*/
CourseBSTNode *createCourseBSTNode(Course *c)
{
    CourseBSTNode *cn = (CourseBSTNode *)malloc(sizeof(CourseBSTNode));
    cn->course = c;
    cn->left = NULL;
    cn->right = NULL;
    return cn;
}

/*
Function: insertCourseBSTNode
-------------------------------------------------
Insert a new course into the course binary search recursively

return: pointer to the node inserted to the bst

param:
root: current root of the bst
newCoursse: pointer to the new course being inserted

*/
CourseBSTNode *insertCourseBSTNode(CourseBSTNode *root, Course *newCourse)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
    {
        CourseBSTNode *newNode = createCourseBSTNode(newCourse);
        return newNode;
    }
    int cmp = strcmp(newCourse->code, root->course->code);
    /* Otherwise, recur down the tree */
    if (cmp < 0)
        root->left = insertCourseBSTNode(root->left, newCourse);
    else if (cmp > 0)
        root->right = insertCourseBSTNode(root->right, newCourse);

    /* return the (unchanged) node pointer */
    return root;
}

/*
Function: insertCourseBST
-------------------------------------------------
Insert a new course into the course binary search tree. This function is 
essentially a wrapper function for insertCourseBSTNode

return: pointer to the node inserted to the bst

param:
bst: pointer to the bst
newCoursse: pointer to the new course being inserted

*/
CourseBSTNode *insertCourseBST(CourseBST *bst, Course *newCourse)
{
    if (bst == NULL)
    {
        printf("BST is NULL (insertion)\n");
        return NULL;
    }
    bst->root = insertCourseBSTNode(bst->root, newCourse);
}

/*
Function: printBSTNode
-------------------------------------------------
Print the bst recursively using pointer to the root.
Inorder

param:
root: pointer to the root

*/
void printBSTNode(CourseBSTNode *root)
{
    if (root != NULL)
    {
        printBSTNode(root->left);
        printCourse(root->course);
        printBSTNode(root->right);
    }
}

/*
Function: printBST
-------------------------------------------------
Print the bst. This function is essentially a wrapper function for 
printBSTNode

param:
bst: pointer to the bst

*/
void printBST(CourseBST *bst)
{
    if (bst != NULL)
    {
        printBSTNode(bst->root);
    }
    else
        printf("BST is NULL\n");
}

/*
Function: searchCourseBST
-------------------------------------------------
Search for a node in the bst by code of course. Wrapper
function for searchCourseBSTNode

param:
bst: pointer to the bst
courseCode: code of the wanted course

*/
CourseBSTNode *searchCourseBST(CourseBST *bst, char *courseCode)
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
        return searchCourseBSTNode(bst->root, courseCode);
    }
}

/*
Function: searchCourseBSTNode
-------------------------------------------------
Search for a node in the bst by code of course.
Go through the bst nodes in a recursive fashion.

param:
root: pointer to the root node
courseCode: code of the wanted course

*/
CourseBSTNode *searchCourseBSTNode(CourseBSTNode *root, char *courseCode)
{
    if (root == NULL)
    {
        printf("Search result: Not Found\n");
        return NULL;
    }
    int cmp = strcmp(courseCode, root->course->code);
    if (cmp == 0)
    {
        return root;
    }
    else if (cmp < 0)
    {
        return searchCourseBSTNode(root->left, courseCode);
    }
    else
    {
        return searchCourseBSTNode(root->right, courseCode);
    }
}