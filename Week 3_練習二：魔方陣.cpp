#include <stdio.h>

int main(){
	int n, i, j;
	scanf("%d",&n);
	int arr[n+1][n+1]={0};
	int a=1, b=(n+1)/2;
	arr[a][b]=1;
	for(i=2;i<=n*n;i++){
		if((a-1)>0 && arr[a-1][b+1]==0){
			if((b+1)<=n){
				arr[a-1][b+1]=i;
				a-=1;b+=1;
			}else{
				b=0;
				arr[a-1][b+1]=i;
				a-=1;b+=1;
			}
		}else if((a-1)==0 && arr[n][b+1]==0){
			a=n+1;
			if((b+1)<=n){
				arr[a-1][b+1]=i;
				a-=1;b+=1;
			}else{
				b=0;
				arr[a-1][b+1]=i;
				a-=1;b+=1;
			}
		}else{
			if((a+1)<=n){
				arr[a+1][b]=i;
				a+=1;
			}else{
				a=0;
				arr[a+1][b]=i;
				a+=1;
			}
		}
	}for(i=1;i<=n;i++){
		for(j=1;j<n;j++){
			printf("%d ",arr[i][j]);
		}printf("%d\n",arr[i][j]);
	}
	return 0;
} 
