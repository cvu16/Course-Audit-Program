#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "courseNode.h"
#include "courseLinkedList.h"
#include "department.h"
#include "degree.h"
#include "degreeArrayList.h"
#include "courseArrayList.h"
#include "deptArrayList.h"

#define MAX 1000

DegreeArrayList *degreeArray;
DeptArrayList *deptArray;

/*
Function : cleanInput
------------------------------------------
Clean the input string from fgets of any end character

input: pointer to the input string

*/
char *cleanInput(char *input)
{
    if (input[0] == ' ')
    {
        input++;
    }
    input[strcspn(input, "\r\n")] = '\0';
    return input;
}

/*
Function : readDept
------------------------------------------
Read in the name of the department and store the information

input: pointer to stdin
name: name of the department

*/
void readDept(FILE *input, char *name)
{
    name = cleanInput(name);
    Department *dept = createDept(name);
    //printf("Department name is: %s\n", dept->name);
    char *currLine = (char *)malloc(MAX * sizeof(char));
    while (!feof(input))
    {
        char *code = (char *)malloc(MAX * sizeof(char));
        char *name = (char *)malloc(MAX * sizeof(char));
        char *preReqs = (char *)malloc(MAX * sizeof(char));
        char *token = (char *)malloc(MAX * sizeof(char));

        fgets(code, MAX, input);
        code = strtok(code, "\n");
        code = cleanInput(code);
        fgets(name, MAX, input);
        name = strtok(name, "\n");
        name = cleanInput(name);
        fgets(preReqs, MAX, input);

        Course *course = createCourse(code, name);
        CourseLinkedList *cll = course->pre;

        if (strncmp(preReqs, "OR", 2) == 0)
        {
            preReqs = preReqs + 3;
            token = strtok(preReqs, ",");
            while (token != NULL)
            {
                token = cleanInput(token);
                insertCourseLinkedList(cll, token);
                token = strtok(NULL, ",");
            }
        }
        addCourseDept(dept, course);
    }
    insertDeptArrayList(deptArray, dept);
}

/*
Function : readDeg
------------------------------------------
Read in the name of the degree and store the information

input: pointer to stdin
name: name of the degree

*/
void readDeg(FILE *input, char *name)
{
    name = strtok(name, "\n");
    name = cleanInput(name);
    Degree *deg = createDeg(name);
    char *currLine = (char *)malloc(MAX * sizeof(char));
    while (!feof(input))
    {
        char *preReqs = (char *)malloc(MAX * sizeof(char));
        char *token = (char *)malloc(MAX * sizeof(char));

        fgets(preReqs, MAX, input);

        DegreeReq *degReq = deg->req;

        if (strncmp(preReqs, "OR", 2) == 0)
        {
            preReqs = preReqs + 3;
            token = strtok(preReqs, ",");
            token = cleanInput(token);
            CourseLinkedList *cll = createCourseLinkedList();
            while (token != NULL)
            {
                token = cleanInput(token);
                printf("%s\n", token);
                insertCourseLinkedList(cll, token);
                token = strtok(NULL, ",");
            }
            insertDegreeReq(degReq, cll);
        }
        else
        {
            CourseLinkedList *cll2 = createCourseLinkedList();
            insertCourseLinkedList(cll2, token);
            insertDegreeReq(degReq, cll2);
        }
    }
    insertDegreeArrayList(degreeArray, deg);
}

/*
Function : fileInput
------------------------------------------
Read in information from a text file given the directory

fileName: directory of the text file including ".txt"
*/
void fileInput(char *fileName)
{
    FILE *input = fopen(fileName, "r");
    if (input == NULL)
    {
        printf("Could not open file\n");
        return;
    }
    char *line = (char *)malloc(MAX * sizeof(char));
    fgets(line, MAX, input);
    line = cleanInput(line);
    //13 because strcmp outputs 13 for no reason when they are equal plus newline
    if (strcmp(line, "DEPARTMENT") == 0)
    {
        char *name = (char *)malloc(MAX * sizeof(char));
        fgets(name, MAX, input);
        readDept(input, name);
        fclose(input);
        return;
    }
    else if (strcmp(line, "DEGREE") == 0)
    {
        char *name1 = (char *)malloc(MAX * sizeof(char));
        fgets(name1, MAX, input);
        readDeg(input, name1);
        fclose(input);
        return;
    }
    else
    {
        printf("Invalid file opener");
        return;
    }
}

/*
Function : commandC
------------------------------------------
Search the department for the course

param: code name of the course

*/
void commandC(char *param)
{
    for (int i = 0; i < deptArray->size; i++)
    {
        Department *dep = deptArray->list[i];
        Course *c = getCourseArrayList(dep->courses, param);
        if (c != NULL)
        {
            printCourse(c);
            return;
        }
    }
    return;
}

/*
Function : commandC
------------------------------------------
Search the degree list for the degree

param: code name of the degree

*/
void commandD(char *param)
{
    Degree *deg = getDegreeArrayList(degreeArray, param);
    if (deg != NULL)
        printDeg(deg);
}

/*
Function : commandS
------------------------------------------
Search the lists of Courses to see what are the courses
that have the code name of the course for prerequisit

param: code name of the course

*/
void commandS(char *param)
{
    for (int i = 0; i < deptArray->size; i++)
    {
        checkPreReq(deptArray->list[i], param);
    }
}

/*
Function : commandLine
------------------------------------------
Get input from the command line (stdin)
to execute waned functions

userInput: the input string recorded from stdin

*/
void commandLine(char *userInput)
{
    if (strcmp(strtok(userInput, "\n"), "x") == 0)
        exit(0);
    char *command = strtok(userInput, " "); //extract the command
    if (strcmp(command, "c") == 0)
    {
        char *courseName = strtok(userInput + 2, "\n");
        commandC(courseName);
    }
    else if (strcmp(command, "d") == 0)
    {
        char *degName = strtok(userInput + 2, "\n");
        commandD(degName);
    }
    else if (strcmp(command, "s") == 0)
    {
        char *courseName = strtok(userInput + 2, "\n");
        commandS(courseName);
    }
    else if (strcmp(command, "p") == 0)
    {
        char *typeName = strtok(userInput + 2, "\n");
        char *type = strtok(typeName, " ");
        char *name = typeName + 2;
        printf("commandP");
    }
}

int main(int argc, char **argv)
{
    degreeArray = createDegreeArrayList();
    deptArray = createDeptArrayList();
    for (int i = 1; i < argc; i++)
    {
        fileInput(argv[i]);
    }
    while (1)
    {
        printf("Type in a command\n");
        char userInput[MAX];
        fgets(userInput, MAX, stdin);
        commandLine(userInput);
    }
}