#include <stdio.h>
#define MAX_TERMS 101
typedef struct {
	int row;
	int col;
	int value;
}term;
term a[MAX_TERMS];
term b[MAX_TERMS];

int main(){
	int n, i, j, sum = 0;
	int c[10][10]={0};
	scanf("%d%*c",&n);
	scanf("(%d:%d)=%d%*c",&a[0].row,&a[0].col,&a[0].value);
	b[0].row = a[0].row;
	b[0].col = a[0].col;
	b[0].value = a[0].value;
	int max;
	if(a[0].col > a[0].row){
		max = a[0].col;
	}else{
		max = a[0].row;
	}
	for(i = 1; i < n; i++){
		scanf("(%d:%d)=%d%*c",&a[i].row,&a[i].col,&a[i].value);
		if(a[i].row > max){
			max = a[i].row;
		}if(a[i].col > max){
			max = a[i].col;
		}b[i].row = a[i].row;
		b[i].col = a[i].col;
		b[i].value = a[i].value;
	}int k = 0, m = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(a[i].col == b[j].col){
				sum += a[i].value * b[j].value;
			}
			c[a[i].row-1][b[j].row-1] += sum;
			sum = 0;
		}
	}
	for(i = 0; i < max; i++){
		for(j = 0; j < max - 1; j++){
			printf("%d ",c[i][j]);
		}printf("%d\n",c[i][j]);
	}
	return 0;
}

/*
3
(1:2)=2
(2:3)=2
(3:2)=3

0 2 0
0 0 2
0 3 0

6
(1:3)=9
(1:5)=-5
(6:2)=6
(7:3)=1
(8:2)=9
(8:7)=3

0 0 9 0 -5 0 0 0
0 0 0 0  0 0 0 0
0 0 0 0  0 0 0 0
0 0 0 0  0 0 0 0
0 0 0 0  0 0 0 0
0 6 0 0  0 0 0 0
0 0 1 0  0 0 0 0
0 9 0 0  0 0 3 0
*/
