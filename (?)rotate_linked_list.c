#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* next;
}node;

//Tail complexity icin tutuldu. Global olmasinin sebebi her fonksyon cagiriminda kaybetmemek.
//Double pointer da olabilirdi. Fonk parametre olarak alacakti.
node* tail = NULL;

void print_ll(node* root){
    node * iter = root;
    while(iter!=NULL){
        printf("%d ",iter->data);
        iter = iter -> next;
    }
    printf("\n");
}

node* push_ll(node* root, int x){

    if(root==NULL){
        root = (node*)malloc(sizeof(node));
        root -> data = x;
        root -> next = NULL;
        tail = root;
    }
    else{
        //tail kullanilarak listenin sonuna kadar gitmeden ekleme yapilabilir.Listenin sonunu tail tutar.
        tail -> next = (node*)malloc(sizeof(node));
        tail = tail -> next;
        tail -> data = x;
        tail -> next = NULL;
    }
    return root;
}

// node* reverse_ll(node* root){
//     //prev, current ve next ile nodelar tutulur.
//     node *prev = NULL;
//     node *next = NULL;
//     node *current = root; // baslangicta sadece current roota esittir digerleri null.
//     //Current null olmadigi surece dongu devam eder.
//     while(current != NULL){
//         next = current -> next;//Once next yerlestirilir currentin onune.
//         current -> next = prev;//Sonrasinda geriye baglanti kurulur.
//         prev = current;//Onceki node u gosteren current a gelir.
//         current = next;//current bir node ilerlerleyip next e gelir.Next null ise dongu biter.
//     }
//     root = prev; // En son prev de root olur.current ve next null olur.
//     return root;// root return edilir.
// }

node* rotate_ll(node *root , int x){
    int counter = 0;
    node* iter = root;
    while( counter < x && iter -> next != NULL){
        iter = iter -> next;
        counter++;
    }
    tail -> next = root;
    root = iter -> next;
    iter -> next = NULL;

    return root;
}

int main(){
    node* root = NULL;
    int op;
    printf("1)Push\n2)Rotate\n3)Print Linked List\n");
    printf("4)Exit\n");
    scanf("%d",&op);

    while(op != 4){
        if(op==1){
            int number;
            printf("Enter the number to push linked list\n");
            scanf("%d",&number);
            root = push_ll(root,number);
        }
        else if(op==2){
            int number;
            printf("Enter the number to rotate value to shifting linked list\n");
            scanf("%d",&number);
            root = rotate_ll(root,number);
        }
        else if(op==3){
            print_ll(root);
        }
        else{
            printf("Invalid Choice\n");
        }
        printf("1)Push\n2)Rotate\n3)Print Linked List\n");
        printf("4)Exit\n");
        scanf("%d",&op);
    }
}
