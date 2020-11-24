#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseLinkedList.h"
#include "studentBST.h"

/*
Function: createStudentBST
-------------------------------------------------
Returns a pointer to a newly allocated student binary search tree

return: pointer to a new binary search tree
*/
StudentBST *createStudentBST()
{
    StudentBST *bst = (StudentBST *)malloc(sizeof(StudentBST));
    bst->root = NULL;
    return bst;
}

/*
Function: createStudentBSTNode
-------------------------------------------------
Create a new node with a given course pointer

param:
c: pointer to the course in the new node
*/
StudentBSTNode *createStudentBSTNode(char *name)
{
    StudentBSTNode *cn = (StudentBSTNode *)malloc(sizeof(StudentBSTNode));
    cn->degs = (CourseLinkedList *)malloc(sizeof(CourseLinkedList));
    cn->completed = (CourseLinkedList *)malloc(sizeof(CourseLinkedList));
    cn->name = (char *)malloc(1000 * sizeof(char));
    strcpy(cn->name, name);
    cn->left = NULL;
    cn->right = NULL;
    return cn;
}

/*
Function: insertStudentBSTNode
-------------------------------------------------
Insert a new student into the student binary search recursively

return: pointer to the node inserted to the bst

param:
root: current root of the bst
newCoursse: pointer to the new Student being inserted

*/
StudentBSTNode *insertStudentBSTNode(StudentBSTNode *root, char *name)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
    {
        StudentBSTNode *newNode = createStudentBSTNode(name);
        return newNode;
    }
    int cmp = strcmp(name, root->name);
    /* Otherwise, recur down the tree */
    if (cmp < 0)
        root->left = insertStudentBSTNode(root->left, name);
    else if (cmp > 0)
        root->right = insertStudentBSTNode(root->right, name);

    /* return the (unchanged) node pointer */
    return root;
}

/*
Function: insertStudentBST
-------------------------------------------------
Insert a new Student into the Student binary search tree. This function is 
essentially a wrapper function for insertStudentBSTNode

return: pointer to the node inserted to the bst

param:
bst: pointer to the bst
newCoursse: pointer to the new Student being inserted

*/
StudentBSTNode *insertStudentBST(StudentBST *bst, char *name)
{
    if (bst == NULL)
    {
        printf("BST is NULL (insertion)\n");
        return NULL;
    }
    bst->root = insertStudentBSTNode(bst->root, name);
}

/*
Function: printStudentBSTNode
-------------------------------------------------
Print the bst recursively using pointer to the root.
Inorder

param:
root: pointer to the root

*/
void printStudentBSTNode(StudentBSTNode *root)
{
    if (root != NULL)
    {
        printStudentBSTNode(root->left);
        if (root->name != NULL)
            printf("%s\n", root->name);
        if (root->degs != NULL)
        {
            printf("Degrees: ");
            printCourseLinkedList(root->degs);
        }
        if (root->completed != NULL)
        {
            printf("Completed: ");
            printCourseLinkedList(root->completed);
        }
        printStudentBSTNode(root->right);
    }
}

/*
Function: printStudentBST
-------------------------------------------------
Print the bst. This function is essentially a wrapper function for 
printBSTNode

param:
bst: pointer to the bst

*/
void printStudentBST(StudentBST *bst)
{
    if (bst == NULL)
    {
        printf("This bst doesn't exist.\n");
    }
    else if (bst->root == NULL)
    {
        printf("There is no student in this student bst.\n");
    }
    else if (bst != NULL)
    {
        printStudentBSTNode(bst->root);
    }
}

/*
Function: searchStudentBST
-------------------------------------------------
Search for a node in the bst by code of Student. Wrapper
function for searchStudentBSTNode

param:
bst: pointer to the bst
name: name of the wanted student

*/
StudentBSTNode *searchStudentBST(StudentBST *bst, char *name)
{
    if (bst == NULL)
    {
        printf("NULL StudentBST\n");
        return NULL;
    }
    else if (bst->root == NULL)
    {
        printf("Empty Student BST\n");
        return NULL;
    }
    else
    {
        return searchStudentBSTNode(bst->root, name);
    }
}

/*
Function: searchStudentBSTNode
-------------------------------------------------
Search for a node in the bst by code of Student.
Go through the bst nodes in a recursive fashion.

param:
root: pointer to the root node
name: name of the wanted student

*/
StudentBSTNode *searchStudentBSTNode(StudentBSTNode *root, char *name)
{
    if (root == NULL)
    {
        printf("Search result: Not Found\n");
        return NULL;
    }
    int cmp = strcmp(name, root->name);
    if (cmp == 0)
    {
        return root;
    }
    else if (cmp < 0)
    {
        return searchStudentBSTNode(root->left, name);
    }
    else
    {
        return searchStudentBSTNode(root->right, name);
    }
}

/* Given a non-empty binary search 
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
StudentBSTNode *minValueStudentBSTNode(StudentBSTNode *root)
{
    StudentBSTNode *current = root;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/*
Function: removeStudentBSTNode
-------------------------------------------------
Search for a node in the bst by code of Student and remove it.
Go through the bst nodes in a recursive fashion.

param:
root: pointer to the root node
name: name of the wanted Student

*/
StudentBSTNode *removeStudentBSTNode(StudentBSTNode *root, char *name)
{
    // base case
    if (root == NULL)
        return root;
    int cmp = strcmp(name, root->name);
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (cmp < 0)
        root->left = removeStudentBSTNode(root->left, name);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (cmp > 0)
        root->right = removeStudentBSTNode(root->right, name);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            StudentBSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            StudentBSTNode *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        StudentBSTNode *temp = minValueStudentBSTNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->name = temp->name;
        root->degs = temp->degs;
        root->completed = temp->completed;

        // Delete the inorder successor
        root->right = removeStudentBSTNode(root->right, temp->name);
    }
    return root;
}

/*
Wrapper function for the removeStudentBSTNode function
*/
StudentBSTNode *removeStudentBST(StudentBST *bst, char *name)
{
    if (bst == NULL)
    {
        printf("NULL StudentBST\n");
        return NULL;
    }
    else if (bst->root == NULL)
    {
        printf("Empty Student BST\n");
        return NULL;
    }
    else
    {
        bst->root = removeStudentBSTNode(bst->root, name);
        return bst->root;
    }
}

//Methods for the studentBSTNode
/*
Function: addCompleteCourseStudent
----------------------------------
Retrieve the address of the student's completed course list and add a new course

param
student: the address of the student node
code: the code of the newly completed course
*/
CourseLinkedList *addCompletedCourseStudent(StudentBSTNode *student, char *code)
{
    if (student == NULL)
        return NULL;
    CourseLinkedList *curr = student->completed;
    if (curr == NULL)
        curr = createCourseLinkedList();
    insertCourseLinkedList(curr, code);
    return curr;
}

/*
Function: addDegreeStudent
----------------------------------
Retrieve the address of the student's degree list and add a new course

param
student: the address of the student node
degree: the name of the new degree
*/
CourseLinkedList *addDegreeStudent(StudentBSTNode *student, char *degree)
{
    if (student == NULL)
        return NULL;
    CourseLinkedList *currdeg = student->degs;
    if (currdeg == NULL)
        currdeg = createCourseLinkedList();
    insertCourseLinkedList(currdeg, degree);
    return currdeg;
}