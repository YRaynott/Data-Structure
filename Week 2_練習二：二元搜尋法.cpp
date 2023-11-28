#include <stdio.h>

void binsearch(int list[], int n, int left, int right){
	int mid;
	while(left <= right)
	{
		mid = (left + right)/2;
		if(n < list[mid])
		{
			right = mid - 1;
		}
		else if(n == list[mid])
		{
			printf("%d\n",mid);
			break;
		}
		else
		{
			left = mid + 1;
		}
	}
}

int main(){
	int n, k, i;
	scanf("%d%d",&n,&k);
	int list[k];
	for(i = 0; i < k; i++)
	{
		scanf("%d",&list[i]);
	}
	binsearch(list,n,0,k-1);
	return 0;
}
