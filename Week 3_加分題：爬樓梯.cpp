#include <stdio.h>

int main(){
	int n, list[1000], i;
	scanf("%d",&n);
	list[0]=0;
	list[1]=1;
	for(i=2;i<1000;i++){
		list[i]=list[i-1]+list[i-2];
	}printf("%d\n",list[n+1]);
	return 0;
}
