#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n* left;
    struct n* right;
}node;

node* add_node(node* tree , int x){
    if(tree == NULL){
        tree = (node*)malloc(sizeof(node));
        tree -> data = x;
        tree -> left = NULL;
        tree -> right = NULL;
    }
    else{
        if(tree -> data < x){
            //Agacin sagina ya da soluna esitlemeyi unutma!.
            tree -> right = add_node(tree -> right , x);
        }
        else{
            tree -> left = add_node(tree -> left , x);
        }
    }
    return tree;
}

void print_tree(node* tree){
    if(tree == NULL){
        return;
    }
    else{
        print_tree(tree -> left);
        printf("%d ",tree -> data);
        print_tree(tree -> right);
    }
}

int search_tree(node* tree , int x){
    //En zor kismi.
    if(tree == NULL){
        //agac null ise -1 dondur
        return -1;
    }
    //agacin datasi aranan sayiya esitse 1 dondur
    if(tree -> data == x){
        return 1;
    }
    //agacin sagini ara eger datayi bulursan bu 1 e esit olur. 1 dondur
    if(search_tree(tree -> right ,x)==1){
        return 1;
    }
    //aynisi sol icin
    if(search_tree(tree -> left ,x)==1){
        return 1;
    }
    //eger hic biri saglanmazsa -1 dondur.
    return -1;
}

int find_max(node* tree){
    while(tree -> right != NULL){
        tree = tree -> right;
    }
    return tree -> data;
}

node *remove(node *tree,int x)
{
if(tree==NULL)
   return NULL;
if(tree->data==x)   { //deger bulundu
   if(tree->left==NULL && tree->right==NULL)  //bulunan degerin sag ve solu NULL
       return NULL;
   if(tree->right!=NULL){ // deger bulundu ve sag tarafı NULL degil
       tree->data=min(tree->right); //sagdaki en küçük değeri al
    tree->right=remove(tree->right,min(tree->right));
    return tree;
   }
 tree->data=max(tree->left); // deger bulundu ve sol taraf NULL degil
 tree->left=sil(tree->left,max(tree->left)); //soldaki en büyük degeri al
 return tree;
 }
 if(tree->data<x) //Deger henüz bulunmadı, x degeri küçükse sol ağacta ara
 {
  tree->right=sil(tree->right,x);
  return tree;
 }
 tree->left=sil(tree->left,x); //deger henüz bulunmadı, x degeri büyükse sağ agacta ara
 return tree;

}﻿

int main(){
    node *tree = NULL;
    int op;
    printf("Enter the operation\n");
    printf("1)Add Node\n2)Find Max\n3)Search data\n4)Delete Node\n5)Print Tree\n6)Exit\n");
    scanf("%d",&op);
    while(op != 6){
        if(op == 1){
            int number;
            printf("Enter the number to add tree\n");
            scanf("%d",&number);
            tree = add_node(tree,number);
        }
        else if(op == 2){
            printf("%d is max number in tree \n",find_max(tree));
        }
        else if(op == 3){
            int number;
            printf("Enter the number to search in tree\n");
            scanf("%d",&number);

            if(1 == search_tree(tree,number) ){
                printf("%d found in tree\n",number);
            }
            else{
                printf("%d is not in tree\n",number);
            }
        }
        else if(op == 4){
            int number;
            printf("Enter the number to delete from tree\n");
            scanf("%d",&number);
            tree = remove(tree,number);
        }
        else if(op == 5){
            print_tree(tree);
        }
        else{
            printf("Invalid Choice\n");
        }
        printf("Enter the operation\n");
        printf("1)Add Node\n2)Find Max\n3)Search data\n4)Delete Node\n5)Print Tree\n6)Exit\n");
        scanf("%d",&op);
    }
}
