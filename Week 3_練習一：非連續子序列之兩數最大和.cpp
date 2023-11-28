#include <stdio.h>

int main(){
	int n, i, j;
	scanf("%d",&n);
	int L[n], max1, max2;
	for(i=0;i<n;i++){
		scanf("%d",&L[i]);
	}for(i=0;i<n;i++){
		if(L[i]>max1){
			max1=L[i];
			j=i;
		}
	}for(i=0;i<n;i++){
		if(L[i]>max2&&max1!=max2&&max2!=j-1&&max2!=j+1){
			max2=L[i];
		}
	}printf("%d\n",max1+max2);
	return 0;
}
