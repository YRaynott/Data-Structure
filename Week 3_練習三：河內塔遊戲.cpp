#include <stdio.h>
#include <stdlib.h>
#define to_ to-'A'
#define from_ from-'A'
#define aux_ aux-'A'

int step, z;

void move(char from, char to, char aux, int n, int pegs[][10], int npegs[]){
	int j;
	static int num;
	if(z==0){
		npegs[0]=n;
		num=n;
		for(j=0;j<n;j++){
			pegs[0][z]=n-z;
		}
	}
	z++;
	if(n==1){
		npegs[from_]--;
		pegs[to_][npegs[to_]]=pegs[from_][npegs[from_]];
		npegs[to_]++;
		step++;
		printf("%d\n",n);
	}else{
		move(from,aux,to,n-1,pegs,npegs);
		npegs[from_]--;
		pegs[to_][npegs[to_]]=pegs[from_][npegs[from_]];
		npegs[to_]++;
		step++;
		printf("%d\n",n);
		move(aux,to,from,n-1,pegs,npegs);
	}
}

int main(){
	int n, i, j;
	int pegs[3][10];
	char start='A', support='B', end='C';
	scanf("%d",&n);
	int npegs[3]={n,0,0};
	for(j=0;j<n;j++){
		pegs[0][j]=n-j;
	}
	move(start,end,support,n,pegs,npegs);
	step=z=0;
	return 0;
}
