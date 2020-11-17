#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Used to unit test each data structure created. Unit tests stored here so
that they can be run/modified easily. Just uncomment the test you want.
Include has to be re-written for each test (I mean isn't that the point)
*/

#include "courseNode.h"
#include "courseLinkedList.h"
#include "course.h"
#include "courseBST.h"
#include "department.h"

/* CourseBST Unit Test
void main()
{
    printf("Test file running\n");
    CourseBST *bst = createCourseBST();
    Course *course1 = createCourse("Psych 110", "Intro to Psych");
    Course *course2 = createCourse("Psych 210", "Medium Psych");
    Course *course3 = createCourse("Psych 310", "Big Psych");
    Course *course4 = createCourse("Psych 200", "XMed Psych");
    insertCourseBST(bst, course1);
    insertCourseBST(bst, course2);
    insertCourseBST(bst, course3);
    insertCourseBST(bst, course4);
    removeCourseBST(bst, "Psych 200");
    printBST(bst);
    printBSTNode(searchCourseBST(bst, "Psych 200"));
}
*/

/*CourseLinkedList Unit Test
void main()
{
    printf("Test file running\n");
    CourseLinkedList *cll = createCourseLinkedList();
    insertCourseLinkedList(cll, "Psych 111");
    insertCourseLinkedList(cll, "Psych 211");
    insertCourseLinkedList(cll, "Psych 311");
    insertCourseLinkedList(cll, "Psych 411");
    CourseLinkedList *result = searchCourseLinkedList(cll, "Psych 111");
    CourseLinkedList *result1 = searchCourseLinkedList(cll, "Psych 112");
    cll = removeCourseLinkedList(cll, "Psych 411");
    if (result1 == NULL)
    {
        printf("NOT FOUND\n");
    }
    else
        printCourseLinkedList(result1);

    if (result == NULL)
    {
        printf("NOT FOUND\n");
    }
    else
        printCourseLinkedList(result);
}
*/

/*
//Unit tests for removing, adding and searching prereqs in a course
void main()
{
    Course *c = createCourse("Psych 320", "Advance to Psych");
    addCourseReq(c, "Psych 110");
    addCourseReq(c, "Psych 220");
    addCourseReq(c, "Psych 223");
    removePrereqInCourse(c, "Psych 220");
    printCourse(c);
    //printCourse(searchPrereqInCourse(c, "Psych 110"));
}
*/

void main()
{
    Course *c1 = createCourse("Psych 320", "Advance to Psych");
    addCourseReq(c1, "Psych 110");
    addCourseReq(c1, "Psych 220");
    Course *c2 = createCourse("Psych 444", "Advance B to Psych");
    addCourseReq(c2, "Psych 333");
    addCourseReq(c2, "Psych 222");
    Course *c3 = createCourse("Psych 555", "Advance C to Psych");
    addCourseReq(c3, "Psych 444");
    addCourseReq(c3, "Psych 333");
    CourseBST *cbst = createCourseBST();
    insertCourseBST(cbst, c1);
    insertCourseBST(cbst, c2);
    insertCourseBST(cbst, c3);
    //printBST(cbst);
    Department *dept = createDept("Psychology");
    addCourseDept(dept, c1);
    addCourseDept(dept, c2);
    addCourseDept(dept, c3);
    //removeCourseDept(dept, "Psych 555");
    removePrereqDept(dept, "Psych 333");
    printDept(dept);
    //printDept(dept);
}