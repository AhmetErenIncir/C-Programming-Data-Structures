#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n* next;
};
typedef struct n node;

int main(){
	node* root;
	root = (node*)malloc(sizeof(node));
	root->data = 10;
	root->next = (node*)malloc(sizeof(node));
	root->next->data = 20;
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->data = 30;
	root->next->next->next = NULL;
	printf("%d ",root->data);
	printf("%d ",root->next->data);
	printf("%d \n",root->next->next->data);
	node* iter;
	iter = root;
	printf("%d ",iter->data);
	printf("%d ",iter->next->data);
	printf("%d ",iter->next->next->data);
}
