CC=gcc
CFLAGS=-I.
DEPS = main.c course.c course.h courseArrayList.c courseArrayList.h courseNode.c courseNode.h courseLinkedList.c courseLinkedList.h degree.c degree.h degreeArrayList.c degreeArrayList.h department.c department.h degreeReq.c degreeReq.h deptArrayList.c deptArrayList.h test.c unitTest.c courseBST.c courseBST.h
OBJ = main.o course.o courseArrayList.o courseNode.o courseLinkedList.o degree.o degreeArrayList.o department.o degreeReq.o deptArrayList.o
TEST = test.o course.o courseArrayList.o courseNode.o courseLinkedList.o degree.o degreeArrayList.o department.o degreeReq.o deptArrayList.o
unitTest = unitTest.o courseBST.o course.o courseNode.o courseLinkedList.o department.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

project: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

test: $(TEST)
	$(CC) -g -o $@ $^ $(CFLAGS)

unitTest: $(unitTest)
	$(CC) -g -o $@ $^ $(CFLAGS)