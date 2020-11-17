#ifndef DEPT_H_
#define DEPT_H_
#include "course.h"
#include "degree.h"

typedef struct Department
{
    char *name;
    struct CourseBST *courses;
} Department;

extern Department *createDept(char *name);
extern void addCourseDept(Department *dept, Course *course);
extern void removeCourseDept(Department *dept, char *courseCode);
extern void removePrereqDept(Department *dept, char *courseCode);
extern void printDept(Department *dept);
extern void checkPreReq(Department *dept, char *code);

#endif