#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, max = 0, i, j;
	int arr[100][100] = {0};
	while(scanf("%d%d",&a,&b)==2){
		if(a > b){
			if(a > max){
				max = a;
			}
		}else{
			if(b > max){
				max = b;
			}
		}arr[a][b] = 1;
		arr[b][a] = 1;
	}printf("Adjacency matrix:\n");
	for(i = 0; i <= max; i++){
		for(j = 0; j < max; j++){
			printf("%d ",arr[i][j]);
		}printf("%d\n",arr[i][j]);
	}printf("\nAdjacency list:\n");
	for(i = 0; i <= max; i++){
		printf("%d: ",i);
		for(j = 0; j < max; j++){
			if(arr[i][j] == 1){
				printf("%d -> ",j);
			}
		}if(arr[i][j] == 1){
			printf("%d -> end\n",j);
		}else{
			printf("end\n");
		}
	}
	return 0;
}

/*
0 3
1 2
1 3
2 3
*/
