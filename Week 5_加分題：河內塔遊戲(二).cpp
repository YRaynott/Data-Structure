#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define to_ to-'A'
#define from_ from-'A'
#define aux_ aux-'A'

int step, z, k;

void print(int pegs[][10], int npegs[3], int num){
	int i, j;
	char p;
	for(i = 0; i < 3; i++){
		p='A'+i;
		printf("%c:",p);
		for(j = 0;j < npegs[i];j++){
			printf(" %d",pegs[i][j]);
		}printf("\n");
	}
}

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
		if(step != (pow(2,k)-1) && step % 5 == 0){
			printf("***********************************\n");
			printf("After Moved %d Times:\n",step);
			print(pegs,npegs,num);
		}
	}else{
		move(from,aux,to,n-1,pegs,npegs);
		npegs[from_]--;
		pegs[to_][npegs[to_]]=pegs[from_][npegs[from_]];
		npegs[to_]++;
		step++;
		if(step != (pow(2,k)-1) && step % 5 == 0){
			printf("***********************************\n");
			printf("After Moved %d Times:\n",step);
			print(pegs,npegs,num);
		}
		move(aux,to,from,n-1,pegs,npegs);
	}
}

int main(){
	int r, n, i, j;
	int pegs[3][10];
	char start='A', support='B', end='C';
	scanf("%d",&n);
	k = n;
	int npegs[3]={n,0,0};
	for(j=0;j<n;j++){
		pegs[0][j]=n-j;
	}
	printf("Number of Discs: %d\n",n);
	printf("***********************************\n");
	printf("Initial State:\n");
	printf("A: ");
	for(i = n; i > 1; i--){
		printf("%d ",i);
	}printf("%d\nB:\nC:\n",i);
	move(start,end,support,n,pegs,npegs);
	printf("***********************************\n");
	printf("Total Moved %d Times:\n",step);
	print(pegs,npegs,n);
	step=z=0;
	return 0;
}
