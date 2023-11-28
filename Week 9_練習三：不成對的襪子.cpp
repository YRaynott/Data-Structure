#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode *listPointer;
struct listNode{
	char data[10];
	listPointer link;
};

listPointer first = NULL;

void insert(listPointer *first, int j){
	listPointer temp, x;
	temp = (listPointer)malloc(sizeof(*temp));
	scanf("%s",temp->data);
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

void compare(listPointer first, int n){
	listPointer x, y;
	x = (listPointer)malloc(sizeof(*x));
	y = (listPointer)malloc(sizeof(*y));
	int t = 0;
	x = first;
	for(; x->link; x = x->link){
		for(y = x->link; y; y = y->link){
			if(strcmp(x->data,y->data) == 0){
				t++;
				break;
			}
		}
	}printf("%d\n",n-t*2);
}

int main(){
	int n, i, t;
	scanf("%d",&n);
	int m[n];
	for(i = 0; i < n; i++){
		scanf("%d",&m[i]);
	}for(i = 0; i < n; i++){
		int j;
		for(j = 0; j < m[i]; j++){
			insert(&first,j);
		}compare(first,m[i]);
		first = NULL;
	}
	return 0;
}

/*
4
6
3
5
2
AAA
CCC
AABA
AABA
AAA
CCC
AABA
AAC
AAC
AABCA
AABCD
AABCA
AABCD
AABC
AABCDD
AAD

2
3
5
ACD
BBCD
ADE
BDD
BDD
ACDB
BDD
ACC
*/
