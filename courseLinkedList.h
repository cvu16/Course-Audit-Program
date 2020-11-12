#ifndef CLL_H_
#define CLL_H_
typedef struct CourseLinkedList
{
    struct CourseNode *first;
} CourseLinkedList;

extern CourseLinkedList *createCourseLinkedList();
extern void printCourseLinkedList(CourseLinkedList *list);
extern void insertCourseLinkedList(CourseLinkedList *list, char *newData);
extern CourseLinkedList *searchCourseLinkedList(CourseLinkedList *list, char *tar);

#endif