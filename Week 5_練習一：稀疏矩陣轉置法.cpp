#include <stdio.h>
#define MAX_TERMS 101
#define COMPARE(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1 )
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

typedef struct {
	int row;
	int col;
	int value;
}term;
term a[MAX_TERMS];
term b[MAX_TERMS];


int main(){
	scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].value);
	int i, j;
	for(i = 1; i <= a[0].value; i++){
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
	}b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	for(i = 1; i <= b[0].value; i++){
		b[i].row = a[i].col;
		b[i].col = a[i].row;
		b[i].value = a[i].value;
	}for(i = 1; i <= b[0].value - 1; i++){
		for(j = i + 1; j <= b[0].value; j++){
			switch(COMPARE(b[i].row, b[j].row)){
			int tempr, tempc, tempv;
				case -1:
					break;
				case 0:
					switch(COMPARE(b[i].col, b[j].col)){
						case -1:
							break;
						case 0:
							break;
						case 1:
							SWAP(b[i].col, b[j].col, tempc);
							SWAP(b[i].value, b[j].value, tempv);
					}break;
				case 1:
					SWAP(b[i].row, b[j].row, tempr);
					SWAP(b[i].col, b[j].col, tempc);
					SWAP(b[i].value, b[j].value, tempv);
			}
		}
	}for(i = 0; i <= b[0].value; i++){
		printf("%d %d %d\n",b[i].row,b[i].col,b[i].value);
	}
	return 0;
}

/*
6 6 8
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28
*/
