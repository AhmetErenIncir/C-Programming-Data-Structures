#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct binary{
    int data;
    struct binary * left;
    struct binary * right;
}bst;

typedef struct q{
    int data;
    struct q * next;
}queue;

typedef struct stck{
    int data;
    struct stck * next;
}stack;

void print_bst(bst *bst_){
    bst *iter = bst_;
    if(iter != NULL){
        print_bst(iter->right);
        printf("%d ",iter->data);
        print_bst(iter->left);
    }
}

void print_stack(stack *stack_){
    if(stack_ == NULL){
        printf("Stack is empty\n");
    }
    else{
        stack * iter = stack_;
        printf("Ordered Stack : ");
        while(iter -> next != NULL){
            printf("%d ",iter -> data);
            iter = iter -> next;
        }
        printf("%d\n",iter->data);
    }
}

void print_queue(queue *queue_){
    if(queue_ == NULL){
        printf("Queue is empty\n");
    }
    else{
        queue *iter = queue_;
        printf("Ordered Queue : ");
        while (iter -> next != NULL) {
            printf("%d ",iter -> data );
            iter = iter -> next;
        }
        printf("%d\n",iter->data);
    }
}

int print_nth_stack(stack * stack_ , int index){
    int counter = 1 , nth;
    stack * iter = stack_;
    while(iter != NULL){
        if(counter == index){
            nth = iter -> data;
        }
        counter++;
        iter = iter -> next;
    }
    return nth;
}
int print_nth_queue(queue * queue_ , int index){
    int counter = 1 , nth;
    queue * iter = queue_;
    while(iter != NULL){
        if(counter == index){
            nth = iter -> data;
        }
        counter++;
        iter = iter -> next;
    }
    return nth;
}

void print_nth_bst_helper(bst *bst_ , int n , int *count , int *res){

    if(bst_ == NULL || n <(*count) ){
        return;
    }
    print_nth_bst_helper(bst_->right , n , count , res);

    (*count)++;

    if((*count) == n){
        (*res) = bst_ ->data;
    }

    print_nth_bst_helper(bst_->left , n , count , res);
}

int print_nth_bst(bst * bst_ , int n){
    int count = 0;
    int res;
    print_nth_bst_helper(bst_ , n , &count , &res);
    return res;
}

void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]){

    int i = 0;

    //Filling Stack.
    clock_t start_stack, end_stack;
    start_stack = clock();
    for(i=0 ; i <= 19 ; i++){
        if(*stack_ == NULL){
            *stack_ = (stack*)malloc(sizeof(stack));
            (*stack_) -> data = data[i];
            (*stack_) -> next = NULL;
        }
        else{
            stack *new_node = (stack*)malloc(sizeof(stack));
            new_node -> data = data[i];
            new_node -> next = *stack_;
            *stack_ = new_node;
        }
    }
    end_stack = clock();
    double total_time_stack = ((double) (end_stack - start_stack))/10 ;
    printf("Fill Stack Time : %.2f\n",total_time_stack);
    //Ending Filling Stack

    //Start Filling Queue.
    clock_t start_queue, end_queue;
    start_queue = clock();
    for(i=0 ; i <= 19 ; i++){
        if(*queue_ == NULL){
            *queue_ = (queue*)malloc(sizeof(queue));
            (*queue_) -> data = data[i];
            (*queue_) -> next = NULL;
        }
        else{
            queue *new_node = (queue*)malloc(sizeof(queue));
            queue *iter = *queue_;
            new_node -> data = data[i];
            while(iter -> next != NULL){
                iter = iter -> next;
            }
            iter -> next = new_node;
            new_node -> next = NULL;
        }
    }
    end_queue = clock();
    double total_time_queue = ((double) (end_queue - start_queue))/10 ;
    printf("Fill Queue Time : %.2f\n",total_time_queue);
    //Ending Filling Queue

    //Start Filling BST.
    clock_t start_bst, end_bst;
    start_bst = clock();
    for(i=0 ; i<=19 ; i++){
        if(*bst_ == NULL){
            *bst_ = (bst*)malloc(sizeof(bst));
            (*bst_) -> data = data[i];
            (*bst_) -> left = (*bst_) -> right = NULL;
        }
        else{
            bst *iter = *bst_;
            bst *iter2 = NULL;
            while(iter != NULL){
                iter2 = iter;
                if(iter -> data > data[i]){
                    iter  = iter -> left;
                }
                else{
                    iter = iter -> right;
                }
            }
            if(data[i] < iter2 -> data){
                iter2 -> left = (bst*)malloc(sizeof(bst));
                iter2 = iter2 -> left;
                iter2 -> data = data[i];
                iter2 -> left = iter2 -> right = NULL;
            }
            else{
                iter2 -> right = (bst*)malloc(sizeof(bst));
                iter2 = iter2 -> right;
                iter2 -> data = data[i];
                iter2 -> left = iter2 -> right = NULL;
            }
        }
    }
    end_bst = clock();
    double total_time_bst = ((double) (end_bst - start_bst)) / 10;
    printf("Fill BST Time : %.2f\n",total_time_bst);
    //Ending Filling BST

}

void ordered_print(stack * stack_, queue * queue_, bst * bst_){

    int temp;
    stack *i,*j;
    queue *x,*y;
    bst *a,b;

    //Starting stack sort.
    clock_t start_stack, end_stack;
    start_stack = clock();
    for(i = stack_ ; i -> next != NULL ; i = i -> next){
        for(j = i -> next ; j != NULL ; j = j -> next){
            if(i -> data < j -> data){
                temp = i -> data;
                i -> data = j -> data;
                j -> data = temp;
            }
        }
    }
    //Printing stack.
    printf("\n");
    print_stack(stack_);
    end_stack = clock();
    double total_time_stack = ((double) (end_stack - start_stack))/10 ;
    //Ending Stack sort

    //Starting queue sort.
    clock_t start_queue, end_queue;
    start_queue = clock();
    for(x = queue_ ; x -> next != NULL ; x = x -> next){
        for(y = x -> next ; y != NULL ; y = y -> next){
            if(x -> data < y -> data){
                temp = x -> data;
                x -> data = y -> data;
                y -> data = temp;
            }
        }
    }
    //Printing sorted Queue.
    print_queue(queue_);
    end_queue = clock();
    double total_time_queue = ((double) (end_queue - start_queue))/10 ;
    //Ending queue sort.

    //Starting bst sorted-print.
    clock_t start_bst, end_bst;
    start_bst = clock();
    printf("Ordered BST : ");
    print_bst(bst_);
    end_bst = clock();
    double total_time_bst = ((double) (end_bst - start_bst)) / 10;
    //Ending BST sorted-print.
    printf("\n");

    //Printing the structers' order times.
    printf("\nOrder Stack Time : %.2f\n",total_time_stack);
    printf("Order Queue Time : %.2f\n",total_time_queue);
    printf("Order-Print BST Time : %.2f\n",total_time_bst);

}

void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search){

    int counter = 0 , found=0 , counter_f;

    //Start Searching on Stack.
    clock_t start_stack, end_stack;
    start_stack = clock();
    stack * iter_s = stack_;
    while(iter_s != NULL){
        counter++;
        if(iter_s -> data == val_to_search){
            found++;
            counter_f = counter;
        }
        iter_s = iter_s -> next;
    }
    if(found == 0){
        printf("\n%d not found in Stack\n",val_to_search);
    }
    else{
        printf("\n%d result founded on %d. step\n",found,counter_f);
    }
    end_stack = clock();
    double total_time_stack = ((double) (end_stack - start_stack))/10 ;
    //Ending Searching on Stack

    //Start Searching on Queue.
    clock_t start_queue, end_queue;
    start_queue = clock();
    counter = 0;
    found = 0;
    counter_f = 0;
    queue *iter_q = queue_;
    while(iter_q != NULL){
        counter++;
        if(iter_q -> data == val_to_search){
            found++;
            counter_f = counter;
        }
        iter_q = iter_q -> next;
    }
    if(found == 0){
        printf("\n%d not found in Queue\n",val_to_search);
    }
    else{
        printf("%d result founded on %d. step\n",found,counter_f);
    }
    end_queue = clock();
    double total_time_queue = ((double) (end_queue - start_queue))/10 ;
    //Ending Searching on Queue

    //Start Searching on BST.
    clock_t start_bst, end_bst;
    start_bst = clock();
    counter = 1;
    counter_f = 0;
    found = 0;
    bst * iter_b = bst_;
    while(iter_b != NULL){
        if(iter_b -> data == val_to_search){
            found++;
            counter_f = counter;
            iter_b = iter_b -> right;
            counter++;
        }
        else if(iter_b -> data < val_to_search){
            iter_b = iter_b -> right;
            counter++;
        }
        else{
            iter_b = iter_b -> left;
            counter++;
        }
    }
    //Printing founded number and step
    printf("%d result founded on %d. step\n",found,counter_f);
    end_bst = clock();
    double total_time_bst = ((double) (end_bst - start_bst)) / 10;
    //Ending Searching on BST

    printf("\n");

    //Printing the search time for all structers.
    printf("\nSearch Stack Time : %.2f\n",total_time_stack);
    printf("Search Queue Time : %.2f\n",total_time_queue);
    printf("Search BST Time : %.2f\n",total_time_bst);

}

void special_traverse(stack * stack_, queue * queue_, bst * bst_){

    int i;

    //Starting Special Print for Stack.
    clock_t start_stack, end_stack;
    start_stack = clock();
    printf("\n");
    printf("Special Travers Stack : ");
    for(i=1 ; i<=10 ; i++){
        printf("%d ",print_nth_stack(stack_,i));
        printf("%d ",print_nth_stack(stack_,(21-i)) );
    }
    printf("\n");
    end_stack = clock();
    double total_time_stack = ((double) (end_stack - start_stack))/10 ;
    //Ending Special Print for Stack

    //Starting Special print for Queue
    clock_t start_queue, end_queue;
    start_queue = clock();
    printf("Special Travers Queue : ");
    for(i=1 ; i<=10 ; i++){
        printf("%d ",print_nth_queue(queue_,i));
        printf("%d ",print_nth_queue(queue_,(21-i)) );
    }
    printf("\n");
    end_queue = clock();
    double total_time_queue = ((double) (end_queue - start_queue))/10 ;
    //Ending Special Print for Queue

    //Starting Special Print for bst
    clock_t start_bst, end_bst;
    start_bst = clock();
    printf("Special Travers BST : ");
    for(i=1 ; i<=10 ; i++){
        printf("%d ",print_nth_bst(bst_,i));
        printf("%d ",print_nth_bst(bst_,(21-i)));
    }
    printf("\n");
    end_bst = clock();
    double total_time_bst = ((double) (end_bst - start_bst)) / 10;
    //Ending Special Print for bst

    printf("\n");

    //Printing the Special Traverse time for all structers.
    printf("\nSpecial Traverse Stack Time : %.2f\n",total_time_stack);
    printf("Special Traverse Queue Time : %.2f\n",total_time_queue);
    printf("Special Traverse BST Time : %.2f\n",total_time_bst);
    printf("\n");

}
//i did not use const define to save main function.I assumed that array size cannot be changed according to homework PDF.
int main(){
    int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};

    bst * bst_ = NULL;
    queue * queue_ = NULL;
    stack * stack_ = NULL;

    fill_structures(&stack_, &queue_, &bst_, data);
    ordered_print(stack_, queue_, bst_);
    search(stack_, queue_, bst_, 5);
    special_traverse(stack_, queue_, bst_);

    return 0;
}
