#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int arr[30][30] = {0};
int dist[30] = {0};
int len[30] = {0};

void BellmanFord(int n, int v){
	int i, j, k, u;
	for(i = 0; i < n; i++){
		dist[i] = arr[v][i];
		len[i] = arr[v][i];
	}printf("%d",dist[0]);
	for(i = 1; i < n; i++){
		if(dist[i] != INT_MAX){
			printf(" %d",dist[i]);
		}else{
			printf(" i");
		}
	}printf("\n");
	for(k = 2; k <= n-1; k++){		//k:¨B¼Æ 
		for(u = 1; u < n; u++){
			if(u != v){
				for(i = 0; i < n; i++){
					if((arr[i][u] != INT_MAX) && (len[i] != INT_MAX) && (dist[u] > len[i] + arr[i][u])){
						dist[u] = len[i] + arr[i][u];
					}
				}
			}
		}printf("%d",dist[0]);
		for(i = 1; i < n; i++){
			if(dist[i] != INT_MAX){
				printf(" %d",dist[i]);
			}else{
				printf(" i");
			}
		}printf("\n");
		for(i = 0; i < n; i++){
			len[i] = dist[i];
		}
	}
}

int main(){
	int a, b, link, i, j, max = 0;
	while(scanf("%d%d%d",&a,&b,&link)==3){
		arr[a][b] = link;
		if(a > b){
			if(a > max)max = a;
		}else{
			if(b > max)max = b;
		}
	}for(i = 0; i <= max; i++){
		for(j = 0; j <= max; j++){
			if(i != j && arr[i][j] == 0){
				arr[i][j] = INT_MAX;
			}
		}
	}BellmanFord(max+1,0);
	return 0;
}

/*
0	1	6
0	2	5
0	3	5
1	4	-1
2	1	-2
2	4	1
3	2	-2
3	5	-1
4	6	3
5	6	3
*/
