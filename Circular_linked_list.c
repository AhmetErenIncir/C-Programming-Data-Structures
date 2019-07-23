#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	struct n* next;
}node;

void print_circular(node* root){
	if(root==NULL){
		printf("Circular Linked List is empty\n");
	}
	else{
		node* iter = root;
		while(iter -> next != root){
			printf("%d ",iter->data);
			iter = iter -> next;
		}
		printf("%d\n",iter->data);
	}
}

node* add(node* root , int x){
	if(root==NULL){
		root = (node*)malloc(sizeof(node));
		root -> data = x;
		root -> next = root;
	}
	else{
		node* iter = root;
		while(iter -> next !=  root){
			iter = iter -> next;
		}
		iter -> next = (node*)malloc(sizeof(node));
		iter -> next -> data = x;
		iter -> next -> next = root;
	}
	return root;
}

node* delete_cir(node* root , int x){
	node* iter = root;
	if(root == NULL){
		printf("Circular Linked List is empty\n");
	}
	else if(root -> data == x){
		if(root -> next == root){
			root = NULL;
		}
		else{
			node* temp = malloc(sizeof(node));
			node * iter = root;
			while(iter -> next != root){
				iter = iter -> next;
			}
			temp = root;
			root = root -> next;
			iter -> next = root;
			free(temp);
		}

		// //Eger root silinecekse linked list in sonuna gidip onu yeni roota baglamamiz gerekir.
		// node* temp = (node*)malloc(sizeof(node));
		// //node* iter = root;
		// while(iter -> next != root){
		// 	//Linked list in son elemani belirlenir.
		// 	iter = iter -> next;
		// }
		// temp = root;
		// root = root -> next;
		// free(temp);
		// //Yeni root ile son elemanin baglantisi yapilir.
		// // if(root-> next != root){
		// // 	iter -> next = root;
		// // }
		// // else{
		// // 	root = NULL;
		// // }

	}
	else{
		while(iter -> next != root && iter -> next -> data != x){
			iter = iter -> next;
		}
		if(iter -> next == root){
			printf("%d is not in Circular Linked List\n",x);
		}
		else{
			node* temp = (node*)malloc(sizeof(node));
			temp = iter -> next;
			iter -> next = iter -> next -> next;
			free(temp);
		}
	}
	return root;
}

// node *reverse_cll(node* root){
// 	node* current , *next , *tail;
// 	tail = root;
// 	while(tail->next != root){
// 		tail = tail -> next;
// 	}
// 	current = root;
// 	next = NULL;
//
// 	next = current -> next;
// 	current -> next = tail;
// 	next -> next = current;
// 	current = next;
//
// 	while(current != tail){
// 		next = current -> next;
// 		next -> next = current;
// 		current = next;
// 	}
// 	root = tail;
// 	return root;
// }

int main(){
	int number;
	node* root = NULL;
	printf("Enter the number to add Circular Linked List\n");
	scanf("%d",&number);
	while(number != -1){
		root = add(root,number);
		scanf("%d",&number);
	}
	print_circular(root);
	root = reverse_cll(root);
	printf("daida\n");
	print_circular(root);
	//printf("Enter the number to delete\n");
	// scanf("%d",&number);
	// while(number != -1){
	// 	root = delete_cir(root,number);
	// 	print_circular(root);
	// 	scanf("%d",&number);
	// }
}
