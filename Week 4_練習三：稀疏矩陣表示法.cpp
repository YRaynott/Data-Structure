#include <stdio.h>

int main(){
	int m, n, i, j, t = 0;
	int a[100][100];
	scanf("%d%d",&m,&n);
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d",&a[i][j]);
			if(a[i][j] != 0){
				t++;
			}
		}
	}printf("%d %d %d\n",m,n,t);
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(a[i][j] != 0){
				printf("%d %d %d\n",i,j,a[i][j]);
			}
		}
	}
	return 0;
}

/*
3 4
0 2 0 0
0 0 3 0
0 0 1 1
*/
