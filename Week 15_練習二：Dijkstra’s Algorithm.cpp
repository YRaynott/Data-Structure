#include <stdio.h>
#include <stdlib.h>

int arr[30][30] = {0};
int distance[30] = {0};
short int found[30] = {0};

int choose(int distance[], int n, short int found[]){
	int i, min, minpos;
	min = 9000;
	minpos = -1;
	for(i = 0; i < n; i++){
		if((distance[i] < min) && !found[i]){
			min = distance[i];
			minpos = i;
		}
	}return minpos;
}

void shortestPath(int v, int arr[][30], int distance[], int n, short int found[]){
	int i, u, w;
	for(i = 0; i < n; i++){
		found[i] = 0;
		distance[i] = arr[v][i];
	}found[v] = 1;
	distance[v] = 0;
	for(i = 0; i < n; i++){
		u = choose(distance,n,found);
		found[u] = 1;
		for(w = 0; w < n; w++){
			if(!found[w]){
				if((distance[u]+arr[u][w]) < distance[w]){
					distance[w] = distance[u] + arr[u][w];
				}
			}
		}
	}
}

int main(){
	int a, b, link, max, begin;
	scanf("%d",&begin);
	while(scanf("%d%d%d",&a,&b,&link)==3){
		arr[a][b] = link;
		if(a > b){
			if(a > max)max = a;
		}else{
			if(b > max)max = b;
		}
	}int i, j;
	for(i = 0; i <= max; i++){
		for(j = 0; j <= max; j++){
			if(arr[i][j] == 0){
				arr[i][j] = 9000;
			}
		}
	}shortestPath(begin,arr,distance,max+1,found);
	for(i = 0; i <= max; i++){
		printf("%d: %d\n",i,distance[i]);
	}
	return 0;
}

/*
0
0	1	10
0	3	5
1	2	1
1	3	2
2	4	4
3	1	3
3	2	9
3	4	2
4	0	7
4	2	6
*/
