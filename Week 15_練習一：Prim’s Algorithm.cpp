#include <stdio.h>
#include <stdlib.h>

int main(){
	int begin, a, b, max = 0, i, cost = 0, j, min = 900, link, k = 0;
	int arr[30][30] = {0};
	int check[30] = {0};
	scanf("%d",&begin);
	check[begin] = 1;
	while(scanf("%d%d%d",&a,&b,&link)==3){
		arr[b][a] = arr[a][b] = link;
		if(a > b){
			if(a > max)max = a;
		}else{
			if(b > max)max = b;
		}
	}for(i = 1; i <= max; i++){
		for(j = 0; j <= max; j++){
			if((arr[begin][j] != 0) && (arr[begin][j] < min) && (begin != j)){
				if(check[j] == 0){
					min = arr[begin][j];
					a = begin; b = j;
				}else{
					int n, m, search = 900;
					for(n = 0, m = 0; n <= max; n++, m = 0){
						while((check[n] != 0) && (m <= max)){
							if((check[m] == 0) && (arr[n][m] != 0) && (arr[n][m] < search)){
								min = arr[n][m];
								a = n; b = m;
							}m++;
						}
					}
				}
			}
		}printf("%d: <%d,%d>\n",i,a,b);
		arr[a][b] = arr[b][a] = 900;
		check[b] = 1;
		begin = b;
		cost += min;
		min = 900;
	}printf("\nThe cost of minimum spanning tree: %d\n",cost);
	return 0;
}

/*
0
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
