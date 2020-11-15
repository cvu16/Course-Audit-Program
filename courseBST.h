#ifndef COURSE_BST_H_
#define COURSE_BST_H_
#include "course.h"

typedef struct CourseBSTNode
{
    Course *course;
    struct CourseBSTNode *left;
    struct CourseBSTNode *right;
} CourseBSTNode;

typedef struct CourseBST
{
    struct CourseBSTNode *root;
} CourseBST;

extern CourseBST *createCourseBST();
extern CourseBSTNode *createCourseBSTNode(Course *c);
extern CourseBSTNode *insertCourseBSTNode(CourseBSTNode *root, Course *newCourse);
extern CourseBSTNode *insertCourseBST(CourseBST *bst, Course *newCourse);
extern CourseBSTNode *searchCourseBST(CourseBST *bst, char *courseCode);
extern CourseBSTNode *searchCourseBSTNode(CourseBSTNode *root, char *courseCode);
extern CourseBSTNode *removeBSTNode(CourseBSTNode *root, char *courseCode);
extern CourseBSTNode *removeCourseBST(CourseBST *bst, char *courseCode);
extern CourseBSTNode *minValueNode(CourseBSTNode *root);
extern CourseLinkedList *checkPrereqCourseBST(CourseBST *bst, char *courseCode);
extern void printBSTNode(CourseBSTNode *root);
extern void printBST(CourseBST *bst);

#endif