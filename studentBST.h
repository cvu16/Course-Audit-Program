#ifndef STU_BST_H_
#define STU_BST_H_
#include "courseLinkedList.h"

typedef struct StudentBSTNode
{
    char *name;
    CourseLinkedList *degs;
    CourseLinkedList *completed;
    struct StudentBSTNode *left;
    struct StudentBSTNode *right;
} StudentBSTNode;

typedef struct StudentBST
{
    struct StudentBSTNode *root;
} StudentBST;

//Methods for the student BST
extern StudentBST *createStudentBST();
extern StudentBSTNode *createStudentBSTNode(char *name);
extern StudentBSTNode *insertStudentBSTNode(StudentBSTNode *root, char *name);
extern StudentBSTNode *insertStudentBST(StudentBST *bst, char *name);
extern StudentBSTNode *searchStudentBST(StudentBST *bst, char *name);
extern StudentBSTNode *searchStudentBSTNode(StudentBSTNode *root, char *name);
extern StudentBSTNode *removeStudentBSTNode(StudentBSTNode *root, char *name);
extern StudentBSTNode *removeStudentBST(StudentBST *bst, char *name);
extern StudentBSTNode *minValueStudentBSTNode(StudentBSTNode *root);
extern void printStudentBSTNode(StudentBSTNode *root);
extern void printStudentBST(StudentBST *bst);

//Methods for the student BST node
extern CourseLinkedList *addCompletedCourseStudent(StudentBSTNode *student, char *code);
extern CourseLinkedList *addDegreeStudent(StudentBSTNode *student, char *degree);

#endif