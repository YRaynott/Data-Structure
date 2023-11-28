#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePointer;
struct node{
	int vertex;
	nodePointer link;
};
nodePointer graph[100];
short int d_visit[100], b_visit[100];

void insert(nodePointer *x, int b){
	nodePointer temp, y;
	temp = (nodePointer)malloc(sizeof(*temp));
	temp->vertex = b;
	temp->link = NULL;
	if(*x){
		y = (nodePointer)malloc(sizeof(*y));
		y = *x;
		while(y->link){
			y = y->link;
		}y->link = temp;
	}else{
		*x = temp;
	}
}

void dfs(int a){
	nodePointer x;
	d_visit[a] = 1;
	printf("%d",a);
	for(x = graph[a]; x; x = x->link){
		if(!d_visit[x->vertex]){
			printf(" ");
			dfs(x->vertex);
		}
	}
}

void bfs(int a, int max){
	nodePointer x;
	int i;
	printf("%d",a);
	b_visit[a] = 1;
	while(i < max){
		for(x = graph[a]; x; x = x->link){
			if(!b_visit[x->vertex]){
				printf(" %d",x->vertex);
				b_visit[x->vertex] = 1;
				i++;
			}
		}a++;
		if(!b_visit[a]){
			printf(" %d",a);
			b_visit[a] = 1;
			i++;
		}
	}
}

int main(){
	int a, b, max;
	while(scanf("%d%d",&a,&b) == 2){
		if(a > b){
			if(a > max) max = a;
		}else{
			if(b > max) max = b;
		}insert(&graph[a],b);
		insert(&graph[b],a);
	}printf("Depth First Search:\n");
	dfs(0);
	printf("\n");
	printf("\nBreadth First Search:\n");
	bfs(0,max);
	printf("\n");
	return 0;
}

/*
0	3
1	2
1	3
2	3
*/
