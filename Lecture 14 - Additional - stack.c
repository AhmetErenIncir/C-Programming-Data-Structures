#include <stdio.h>
#include <stdlib.h>


typedef struct stack_entry_s {
	char * title;
	int  numpages;
	char authorlast3[3];
	struct stack_entry_s * next;
} stack_entry_t;

typedef struct {
	stack_entry_t * head;
	int n; /* the number of entries in the stack */
	char name[10];
} stack_type;


stack_type void create_stack_v(char * name) {
	stack_type s;
	s.n = 0;
	strcpy(s.name, name);

	s.head = NULL;

	return s;
}

void create_stack_p(stack_type * s, char * name) {
	s->n = 0;
	strcpy(s->name, name);

	s->head = NULL;
}


int push_stack_p(stack_type * s, char * title, 
			char * lastname3, int numpages) {
	stack_entry_t * e;
	e = malloc(sizeo(stack_entry_t));
	e-> next = s->head;
	s->head = e;

	strcpy(e->authorlast3, authorlast3);
	e->numpages = numpages;
	e->title = malloc(sizeof(char)*strlen(title));
	strcpy(e->title, title);
	s->n ++; 
}


int pop_stack_p(stack_type * s, int * numpages, char * title, char * authorlast3) {
	stack_entry_t * e;
	if (s->head == NULL) return -1;
	e = s->head;
	s->head = e->next;
	s->n --;

	free(e->title);
	free(e);
	return 1;
} 



void remove_stack_p(stack_type * s) {
	int i;
	for (i=0;i<s->n;i++) {
		free(s->arr[i].title);
	}
	free(s->arr);
	s->n = 0;
	s->name[0] = 0;
}

int main(int argc, char const *argv[])
{
	stack_type mystack1;
	stack_type mystack2;
	int n;
	char title[1000], ln[10];

	mystack1 = create_stack_v("novels");
	create_stack_p(&mystack2, "comics");

	push_stack_p(&mystack1, "Book1", "Daa", 200);
	push_stack_p(&mystack1, "Book2", "Dab", 100);
	push_stack_p(&mystack1, "Book3", "Dac", 240);
	pop_stack_p(&mystack1, title, ln, &n);

	return 0;
}


