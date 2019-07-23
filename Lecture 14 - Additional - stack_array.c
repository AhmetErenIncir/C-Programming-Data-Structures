#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_ENTRIES 100000


typedef struct {
	char * title;
	int  numpages;
	char authorlast3[3];
} stack_entry_t;

typedef struct {
	stack_entry_t * arr;
	int n; /* the number of entries in the stack */
	char name[10];
} stack_type;


stack_type create_stack_v(char * name) {
	stack_type s;
	s.n = 0;
	strcpy(s.name, name);

	s.arr = (stack_entry_t *)malloc(100*sizeof(stack_entry_t));

	return s;
}

void create_stack_p(stack_type * s, char * name) {
	s->n = 0;
	strcpy(s->name, name);

	s->arr = (stack_entry_t *)calloc(MAX_STACK_ENTRIES, sizeof(stack_entry_t));
}


int push_stack_p(stack_type * s, char * title,
			char * lastname3, int numpages) {
	if (s->n>=MAX_STACK_ENTRIES) return -1;

	s->arr[s->n].authorlast3 = c;
	s->arr[s->n].numpages = numpages;
	s->arr[s->n].title = malloc(sizeof(char)*strlen(title));
	strcpy(s->arr[s->n], title);
	s->n ++;
}


int pop_stack_p(stack_type * s, int * numpages, char * title, char * authorlast3) {
	stack_entry_t e;
	e.title = NULL;
	e.numpages = 0;
	e.authorlast3[0] = 0;

	if (s->n>0) {
		s->n --;
		*numpages = s->arr[s->n].numpages;
		strcpy(authorlast3, s->arr[s->n].authorlast3);
		strcpy(title, s->arr[s->n].title);
		free(s[s->n].title);
		return 1;
	}
	else {
		return -1;
	}
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

	mystack1 = create_stack_v("novels");
	create_stack_p(&mystack2, "comics");


	return 0;
}
