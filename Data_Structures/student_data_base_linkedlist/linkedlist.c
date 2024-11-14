#include "linkedlist.h"


StudentNode*GpFisrtStudent=NULL;

void add_student(Sdata*student){
    StudentNode*CurrentStudent=NULL;
    StudentNode*PLastStudent=NULL;
    if(GpFisrtStudent==NULL){
        CurrentStudent=(StudentNode*)malloc(sizeof(StudentNode));
        GpFisrtStudent=GpFisrtStudent;
        CurrentStudent->PnextStudent=NULL;
    }
    else{
        while(CurrentStudent->PnextStudent)
        {
            PLastStudent=(StudentNode*)malloc(sizeof(StudentNode));
        }
         CurrentStudent->PnextStudent=PLastStudent;
         CurrentStudent=PLastStudent;
         CurrentStudent->PnextStudent=NULL;
    }


    CurrentStudent->StudentData.id=student->id;
    CurrentStudent->StudentData.height=student->height;
    // Manually copy the student name
    for (int i = 0; i < 40; ++i) {
        CurrentStudent->StudentData.name[i] = student->name[i];
        if (student->name[i] == '\0') {
            break; // Stop copying when null terminator is encountered
        }
    }
}
