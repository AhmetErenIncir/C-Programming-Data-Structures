#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_STUDENT 10
#define MAX_LESSON 5

typedef struct lesson{
    int section;
    int credits;
    char *name;
    struct lesson* next;
}lesson_t;

typedef struct student{
    int id;
    lesson_t *array;
}student_t;



void add_lesson(student_t *student){
    student -> id =6;
}

student_t* add_les(student_t * student , int x){
    student = (student_t*)malloc(sizeof(student_t)*MAX_NUMBER_OF_STUDENT);
    student[x].id = 5;
    return student;
}

void add_lesson(student_t *student){

}


int main(){
    /*
    student_t *student = (student_t*)malloc(sizeof(student_t)*MAX_NUMBER_OF_STUDENT);
    student -> array = (lesson_t*)malloc(sizeof(lesson_t)*MAX_LESSON);
    student -> array -> name = (char*)malloc(sizeof(char)*7);
    add_lesson(&student[0]);
    printf("%d\n",student[0].id );
    */

    /*
    student_t *student = NULL;
    student = add_les(student,3);
    printf("%d\n",student[3]);
    */
    int i,number,op;
    student_t *student = (student_t*)malloc(sizeof(student_t)*MAX_NUMBER_OF_STUDENT);

    for(i=0 ; i<MAX_NUMBER_OF_STUDENT ; i++){
        student[i].id = 1000+i;
    }
    printf("1)Add lesson\n2)drop lesson\n3)Exit");
    scanf("%d",&op);

    while(op != 3){
        if(op == 1){
            int id;
            printf("Enter the id\n");
            scanf("%s",&id);
            i=0
            while(id!=student[i].id && i<MAX_NUMBER_OF_STUDENT){
                i++;
            }
            add_lesson(&student[i]);
        }
        else if(op == 2){

        }
        else{
            printf("Invalid choice\n");
        }
        printf("1)Add lesson\n2)drop lesson\n3)Exit");
        scanf("%d",&op);
    }



}
