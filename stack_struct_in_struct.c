#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_OF_STACKS 5
#define MAX_NUM_OF_MOVIES 10


typedef struct movies{
    char *name;
    double imdb;
    int year;
    char *country;
    struct movies* next;
}movies;

typedef struct stack{
    char *name;
    movies *movie;
}stack_t;

void add_to_stack(stack_t * root ){
    root = malloc(sizeof(stack_t));
    root -> name = (char*)malloc(sizeof(char)*20);
    int movie_num;
    printf("Enter the stack name\n");
    scanf("%s",root->name);
    printf("Enter the number of movie\n");
    scanf("%d",&movie_num);
    root -> movie = malloc(sizeof(movies)*movie_num);
    printf("Enter name of movie\n");
    scanf("%s",root -> movie[0] . name );
    printf("Enter imdb score movie\n");
    scanf("%lf ",root -> movie[0] . imdb );
    printf("Enter the country of movie\n");
    scanf("%s",root -> movie[0] . country );
    root -> movie[0] . next = NULL;
}

int main(){
    stack_t stacks[MAX_NUM_OF_STACKS];
    int op;
    add_to_stack(&stacks[0]);
    // printf("1-Push movie to stacks\n");
    // printf("2-Pop movie from stacks\n");
    // printf("3-Show movies on stacks\n");
    // printf("4-Exit\n");
    // scanf("%d",&op);



    // while(op != 4){
    //     if(op == 1){
    //         printf("Enter the stack number\n");
    //         scanf("%d",&number);
    //     }
    //     else if(op == 2){
    //
    //     }
    //     else if(op == 3){
    //
    //     }
    //     else{
    //         printf("Invalid Choice\n");
    //     }
    // }

}
