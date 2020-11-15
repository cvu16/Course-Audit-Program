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

/* Given a non-empty binary search 
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
CourseBSTNode *minValueNode(CourseBSTNode *root)
{
    CourseBSTNode *current = root;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/*
Function: removeCourseBSTNode
-------------------------------------------------
Search for a node in the bst by code of course and remove it.
Go through the bst nodes in a recursive fashion.

param:
root: pointer to the root node
courseCode: code of the wanted course

*/
CourseBSTNode *removeCourseBSTNode(CourseBSTNode *root, char *courseCode)
{
    // base case
    if (root == NULL)
        return root;
    int cmp = strcmp(courseCode, root->course->code);
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (cmp < 0)
        root->left = removeCourseBSTNode(root->left, courseCode);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (cmp > 0)
        root->right = removeCourseBSTNode(root->right, courseCode);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            CourseBSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            CourseBSTNode *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        CourseBSTNode *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->course = temp->course;

        // Delete the inorder successor
        root->right = removeCourseBSTNode(root->right, temp->course->code);
    }
    return root;
}

/*
Wrapper function for the removeCourseBSTNode function
*/
CourseBSTNode *removeCourseBST(CourseBST *bst, char *courseCode)
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
        bst->root = removeCourseBSTNode(bst->root, courseCode);
        return bst->root;
    }
}

/*
Function: checkPrereqCourseBST
--------------------------------
Run search prereq through all the courses within the bst.
If the searchprereq function returns something that isn't null,
add the course's code to a new CLL and return this.


*/
CourseLinkedList *checkPrereqCourseBST(CourseBST *bst, char *courseCode)
{
    CourseLinkedList *cll = createCourseLinkedList();
    CourseBSTNode *curr = bst->root;
    //Traverse the left subtree
    while (curr != NULL)
    {
        Course *course = searchPrereqInCourse(curr->course, courseCode);
        if (course != NULL)
        {
            insertCourseLinkedList(cll, course->code);
        }
        curr = curr->right;
    }
    //Traverse the left subtree
    curr = bst->root;
    while (curr != NULL)
    {
        Course *course = searchPrereqInCourse(curr->course, courseCode);
        if (course != NULL)
        {
            insertCourseLinkedList(cll, course->code);
        }
        curr = curr->left;
    }
    return cll;
}
