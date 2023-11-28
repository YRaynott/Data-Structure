#include <stdio.h>
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))

void sort(int list[], int n){
	int i, j, min, temp;
	for(i = 0; i < n ; i++)  {
		min = i;
		for(j = i+1 ; j < n ; j++)
			if(list[j] < list[min])
				min = j;
				SWAP(list[i],list[min],temp);
	} 
}

int main(){
	int n, i;
	scanf("%d",&n);
	int list[n];
	for(i=0;i<n;i++){
		scanf("%d",&list[i]);
	}sort(list,n);
	for(i=0;i<n-1;i++){
		printf("%d ",list[i]);
	}printf("%d\n",list[n-1]);
	return 0;
}
