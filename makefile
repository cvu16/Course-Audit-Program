CC=gcc
CFLAGS= -g -Wall -I.
DEPS = main.c course.c course.h courseArrayList.c courseArrayList.h courseNode.c courseNode.h courseLinkedList.c courseLinkedList.h degree.c degree.h degreeArrayList.c degreeArrayList.h department.c department.h degreeReq.c degreeReq.h deptArrayList.c deptArrayList.h unitTest.c courseBST.c courseBST.h studentBST.c studentBST.h
OBJ = main.o course.o courseBST.o courseNode.o courseLinkedList.o degree.o degreeArrayList.o department.o degreeReq.o deptArrayList.o studentBST.o
unitTest = unitTest.o courseBST.o course.o courseNode.o courseLinkedList.o department.o degreeReq.o degree.o degreeArrayList.o studentBST.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

project: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

unitTest: $(unitTest)
	$(CC) -g -o $@ $^ $(CFLAGS)