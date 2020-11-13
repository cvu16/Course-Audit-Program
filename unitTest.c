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

void main()
{
    Course *c = createCourse("Psych 320", "Intro to Psych");
    addCourseReq(c, "Psych 110");
    addCourseReq(c, "Psych 220");
    removePrereqInCourse(c, "Psych 110");
    printCourse(searchPrereqInCourse(c, "Psych 110"));
}