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

void bubble(int data[], int top){
	int i, j, tmp;
	for(i = 1; i < top; i*=2){
		if(i*2 >= top){
			if(data[top] < data[i]){
				tmp = data[i];
				data[i] = data[top];
				data[top] = tmp;
			}break;
		}
		if(data[i*2] < data[i*2+1]){
			if(data[i*2] < data[i]){
				tmp = data[i*2];
				data[i*2] = data[i];
				data[i] = tmp;
			}
		}else{
			if(data[i*2+1] < data[i]){
				tmp = data[i*2+1];
				data[i*2+1] = data[i];
				data[i] = tmp;
			}
		}
	}
}

int delet(int data[], int top){
	data[1] = data[top];
	data[top] = 0;
	top--;
	return top;
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
	}while(top != 1){
		print(data,top);
		top = delet(data,top);
		bubble(data,top);
	}print(data,top);
	return 0;
}

/*
1 2 3 4 5
10 6 7 8 12 14
*/
