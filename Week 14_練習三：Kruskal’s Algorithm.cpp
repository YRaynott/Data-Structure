#include <stdio.h>
#include <stdlib.h>

int arr[30][30] = {0};
int parent[30] = {0};

void Union(int i, int j, int n){
	int temp, k, m;
	if(parent[i] > parent[j]){
		temp = parent[i];
		for(k = 0; k < n; k++){
			if(parent[k] == temp){
				parent[k] = parent[j];
			}
		}
	}else if(parent[j] > parent[i]){
		temp = parent[j];
		for(k = 0; k < n; k++){
			if(parent[k] == temp){
				parent[k] = parent[i];
			}
		}
	}
}

int Find(int i, int j){
	if(parent[i] != parent[j]){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int a, b, link, max, i, j ,min = 900, cost = 0, step = 1;
	int check[30] = {0};
	while(scanf("%d%d%d",&a,&b,&link)!=EOF){
		arr[b][a] = arr[a][b] = link;
		if(a > b){
			if(a > max)max = a;
		}else{
			if(b > max)max = b;
		}
	}for(i = 0; i <= max; i++){
		parent[i] = i;
	}while(step <= max){
		for(i = 0; i < max; i++){
			for(j = i+1; j < max+1; j++){
				if(Find(i,j)){
					if((arr[i][j] != 0) && (arr[i][j] < min)){
						min = arr[i][j];
						a = i; b = j;
					}
				}
			}
		}printf("%d: <%d,%d>\n",step++,a,b);
		Union(a,b,max+1);
		arr[a][b] = arr[b][a] = 900;
		cost += min;
		min = 900;
	}printf("\nThe cost of minimum spanning tree: %d\n",cost);
	return 0;
}

/*
0	1	28
0	5	10
1	2	16
1	6	14
2	3	12
3	4	22
3	6	18
4	5	25
4	6	24
*/
