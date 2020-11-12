#ifndef CARR_H_
#define CARR_H_

typedef struct CourseArrayList
{
    struct Course **list;
    int size;
} CourseArrayList;

extern CourseArrayList *createCourseArrayList();
extern void resizeCourseArrayList(CourseArrayList *list);
extern void insertCourseArrayList(CourseArrayList *list, Course *deg);
extern void printCourseArrayList(CourseArrayList *list);
Course *getCourseArrayList(CourseArrayList *degArr, char *name);
extern void checkCourseReq(CourseArrayList *degArr, char *code);

#endif