#include <stdio.h>
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))

void print(int list[], int k){
	int i;
	for(i=0;i<k-1;i++){
		printf("%d ",list[i]);
	}printf("%d\n",list[k-1]);
}

void sort(int list[], int n){
	int i, j, temp;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(list[i]<list[j]){
				SWAP(list[i],list[j],temp);
			}
		}if(i<3){
			print(list,i+1);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int list[n], i;
	for(i=0;i<n;i++){
		scanf("%d",&list[i]);
	}sort(list,n);
	print(list,n);
	return 0;
} 
