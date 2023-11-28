#include <stdio.h>
#include <stdlib.h>

int pre[100], in[100], level[100] = {0};

int search(int m, int n){
	int i, j, left = 0, right = 0;
	for(i = m; i < n; i++){
		if(level[i] != 0){
			right = level[i];
			break;
		}
	}for(i = m; i >= 0; i--){
		if(level[i] != 0){
			left = level[i];
			break;
		}
	}if(right >= left){
		return ++right;
	}else{
		return ++left;
	}
}

int main(){
	int i, j, n = 0, num, max = -1, k = -1;
	int m;
	while(scanf("%d",&num) == 1){
		k = -1;
		for(i = 0; i < n; i++){
			if(pre[i] == num){
				k = 0;
			}
		}if(k == -1){
			pre[n] = num;
			n++;
		}else{
			break;
		}
	}in[0] = num;
	for(i = 1; i < n; i++){
		scanf("%d",&in[i]);
	}for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(pre[i] == in[j]){
				m = search(j ,n);
				level[j] = m;
				if(max < m){
					max = m;
				}
			}
		}
	}for(i = 1; i < max+1; i++){
		printf("%d:",i);
		for(j = 0; j < n; j++){
			if(i == level[j]){
				printf("%d",in[j]);
				break;
			}
		}for(j = j+1; j < n; j++){
			if(i == level[j]){
				printf(",%d",in[j]);
			}
		}printf("\n");
	}
	return 0;
}

/*
2 1 4 3 5
1 2 3 4 5

5 2 1 6 3
1 2 5 6 3

2 4 5 3 1
5 4 3 2 1
*/
