#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[40];
    unsigned int id;
    float height;

}Sdata;


typedef struct StudentNode{
    Sdata StudentData;
    struct StudentNode*PnextStudent;

}StudentNode;


void add_student(Sdata*student);





#endif // LINKEDLIST_H_INCLUDED
