#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "degree.h"
#include "degreeArrayList.h"
#include "courseBST.h"
#include "department.h"

Department *createDept(char *name)
{
    Department *dept = (Department *)malloc(sizeof(Department));
    dept->name = (char *)malloc(1000 * sizeof(char));
    dept->name = strcpy(dept->name, name);
    dept->courses = createCourseBST();
}

void addCourseDept(Department *dept, Course *course)
{
    insertCourseBST(dept->courses, course);
}

void removeCourseDept(Department *dept, char *courseCode)
{
    removeCourseBST(dept->courses, courseCode);
}

void removePrereqDept(Department *dept, char *courseCode)
{
    removePrereqCourseBST(dept->courses, courseCode);
}

void printDept(Department *dept)
{
    printf("%s\n", dept->name);
    printBST(dept->courses);
}

void checkPreReq(Department *dept, char *code)
{
    if (dept == NULL || dept->courses == NULL)
    {
        printf("Department is Null or Empty");
        return;
    }
    printCourseLinkedList(checkPrereqCourseBST(dept->courses, code));
}
