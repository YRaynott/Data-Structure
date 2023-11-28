#include <stdio.h>

typedef struct{
	int key;
}element;
int rear = 0;
int front = 0;

void addq(element queue[], element item, int n){
	if(front == (rear + 1) % n){
		printf("FULL\n");
	}else{
		rear = (rear + 1) % n;
		queue[rear] = item;
	}
}

void deleteq(element queue[], int n){
	if(front == rear){
		printf("EMPTY\n");
	}else{
		front = (front + 1) % n;
		printf("%d\n",queue[front]);
	}
}

int main(){
	int step, n;
	element item;
	scanf("%d",&n);
	element queue[n];
	while(scanf("%d",&step) != EOF){
		if(step == -1){
			break;
		}else if(step == 1){
			scanf("%d",&item);
			addq(queue,item,n);
		}else{
			deleteq(queue,n);
		}
	}
	return 0;
}

/*
3
1 2
1 3
1 4
1 5
0
0
1 5
0
0
0
-1
*/
