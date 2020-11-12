#ifndef CN_H_
#define CN_H_

typedef struct
    CourseNode
{
    char *data;
    struct CourseNode *prev;
    struct CourseNode *next;
} CourseNode;

extern CourseNode *createNode(char *d, CourseNode *p, CourseNode *nx);
extern void printNode(CourseNode *n);

#endif