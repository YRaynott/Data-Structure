#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
struct listNode{
	int data;
	listPointer link; 
};

listPointer first = NULL;

void insert(listPointer *first, int n){
	int i;
	listPointer temp, x;
	for(i = 0; i < n; i++){
		temp = (listPointer)malloc(sizeof(*temp));
		temp->data = i+1;
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
}

void delet(listPointer *first, listPointer trail, listPointer x){
	printf("%d ", x->data);
	trail->link = x->link;
	free(x);
}

int main(){
	int n, a, b, i, j = 0;
	listPointer x;
	scanf("%d%d%d",&n,&a,&b);
	insert(&first,n);
	x = (listPointer)malloc(sizeof(*x));
	x = first;
	for(i = 0; i < a-1; i++){ //從a開始報1 
		x = x->link;
	}
	while(j < n-1){ //做n-1次pop 
		for(i = 1; i < b-1; i++){	//在b前一個去pop掉b 
			if(x->link){
				x = x->link;
			}else{
				x = first;
			}
		}if(x->link){
			delet(&first,x,x->link);
		}else{
			delet(&first,x,first);
		}if(x->link){	//將x指回下一個 
			x = x->link;
		}else{
			x = first;
		}j++;
	}printf("%d\n",x->data);
	return 0;
}
