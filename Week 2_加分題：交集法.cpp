#include <stdio.h>

int main(){
	int n, b, i, j=-1;
	scanf("%d",&n);
	int L[n]= {0};
	int black[n] = {0};
	int t = 0;
	while(scanf("%d",&b)!=EOF){
		black[t] = b;
		t++;
	}int m = 0;
	t = 0;
	while(black[t] != 0){
		for(i = j + 1; m < black[t]; i++){
			L[i] = 1;
			m++;
		}j = i;
		L[j] = 0;
		m = 0; t++;
	}
	for(i = 0; i < n - 1; i++){
		printf("%d ",L[i]);
	}printf("%d\n",L[i]);
	return 0;
}
