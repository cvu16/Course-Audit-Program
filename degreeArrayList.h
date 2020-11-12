#ifndef DEGARR_H_
#define DEGARR_H_

typedef struct DegreeArrayList
{
    struct Degree **list;
    int size;
} DegreeArrayList;

extern DegreeArrayList *createDegreeArrayList();
extern void resizeDegreeArrayList(DegreeArrayList *list);
extern void insertDegreeArrayList(DegreeArrayList *list, Degree *deg);
extern Degree *getDegreeArrayList(DegreeArrayList *degArr, char *name);
extern void printDegreeArrayList(DegreeArrayList *list);

#endif