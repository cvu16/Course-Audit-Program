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
    printBSTNode(searchCourseBST(bst, "Psych 210"));
    //printBST(bst);
}