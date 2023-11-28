#include <stdio.h>
#include <stdlib.h>

void compare(int data[], int top){
	int i, tmp;
	for(i = top; i > 0; i=i/2){
		if(data[i] < data[i/2]){
			tmp = data[i];
			data[i] = data[i/2];
			data[i/2] = tmp;
		}
	}
}

void print(int data[], int top){
	int i;
	for(i = 1; i < top; i++){
		printf("[%d]%d ",i,data[i]);
	}printf("[%d]%d\n",i,data[i]);
}

int main(){
	int n, top = 0;
	int data[100] = {0};
	while(scanf("%d",&n)==1){
		data[++top] = n;
		compare(data,top);
		print(data,top);
	}
	return 0;
}

/*
10 6 7 8 12 14
2 15 21 33 17 56 77 1 101
*/
