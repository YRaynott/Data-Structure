#include <stdio.h>

int main(){
	int n, i, j;
	int begin[1000] = {0};
	int arr[1000] = {0};
	scanf("%d",&n);
	while(1){
		for(i = 0; i < n; i++){
			begin[i] = i + 1;
		}int front = 0;int top = 0;
		int stack[1000] = {0};
		for(i = 0; i < n; i++){
			scanf("%d",&arr[i]);
			if(arr[i] == -1)
				return 0;
		}for(i = 0; i < n; i++){
			//printf("arr=%d begin=%d stack=%d\n",arr[i],begin[front],stack[top]);
			while(arr[i] != begin[front] && arr[i] != stack[top]){
				if(front >= n){
					printf("NO\n");
					break;
				}
				//printf("push\n");
				stack[++top] = begin[front];
				front++;
			}
			if(arr[i] == begin[front]){
				front++;
			}else if(arr[i] == stack[top]){
				stack[top] = 0;
				top--;
			}else{
				//printf("NO\n");
				break;
			}
		}if(i == n){
			printf("YES\n");
		}
	}
	return 0;
}

/*
3
1 2 3
1 3 2
2 3 1
3 1 2
-1

6
1 2 3 4 5 6
4 3 2 5 1 6
6 5 4 3 2 1
1 4 2 5 3 6
6 5 4 1 2 3
1 2 3 6 5 4
-1

7
7 1 2 3 4 5 6
1 2 3 4 5 6 7
7 6 5 4 3 2 1
1 3 5 7 2 4 6
2 4 6 1 3 5 7
-1
*/
