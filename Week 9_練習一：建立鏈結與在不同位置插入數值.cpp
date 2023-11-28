#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
struct listNode{
	int data;
	listPointer link;
};

listPointer first = NULL;

void f_insert(listPointer *first, int num){
	listPointer temp;
	temp = (listPointer)malloc(sizeof(*temp));
	temp->data = num;
	if(*first){
		temp->link = *first;
	}else{
		temp->link = NULL;
	}*first = temp;
}

void a_insert(listPointer *first, int num){
	listPointer temp, x;
	temp = (listPointer)malloc(sizeof(*temp));
	temp->data = num;
	temp->link = NULL;
	if(*first){
		x = (listPointer)malloc(sizeof(*x));
		x = *first;
		while(x->link){
			x = x->link;
		}x->link = temp;
	}else{
		*first = temp;
	}
}

void i_insert(listPointer *first, int num, int addr){
	int i;
	listPointer temp, x;
	temp = (listPointer)malloc(sizeof(*temp));
	temp->data = num;
	temp->link = NULL;
	x = (listPointer)malloc(sizeof(*x));
	x = *first;
	for(i = 0; x->link; x = x->link, i++){
		if(i+1 == addr){
			if(x->link){
				temp->link = x->link;
				x->link = temp;
			}else{
				*first = temp;
			}
		}
	}
}

void print(listPointer first){
    printf("Created Linked list is: ");
    for(; first; first = first->link){
        printf(" %d ",first->data);
    }printf("\n");
}

int main(){
	int n, i, j;
	char c;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		int num, addr;
		while(scanf(" %c",&c)){
			if(c == 'f'){
				scanf("%d",&num);
				f_insert(&first,num);
				print(first);
			}else if(c == 'a'){
				scanf("%d",&num);
				a_insert(&first,num);
				print(first);
			}else if(c == 'i'){
				scanf("%d%d",&num,&addr);
				i_insert(&first,num,addr);
				print(first);
			}else{
				break;
			}
		}if(i != n-1){
			printf("\n");
		}first = NULL;
	}
	return 0;
}

/*
2
f
63
a
25
i
42 1
q
a
69
a
32
f
11
f
8
i
55 2
q
*/
