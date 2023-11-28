#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
struct listNode{
	int data;
	listPointer link;
};

listPointer first = NULL;

void print(listPointer first){
	for(; first->link; first = first->link){
		printf("%d ",first->data);
	}printf("%d\n",first->data);
}

listPointer invert(listPointer lead){
	listPointer middle, trail;
	middle = NULL;
	while(lead){
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}print(middle);
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

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		a_insert(&first,n);
	}invert(first);
	return 0;
}

/*
1 7 5 8
2 52 3 6 123
*/
