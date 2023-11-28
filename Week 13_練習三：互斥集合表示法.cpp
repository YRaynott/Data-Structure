#include <stdio.h>
#include <stdlib.h>

int parent[100];

void Find(int i, int j){
	if(parent[i] == parent[j]){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}

void Union(int i, int j, int n){
	int temp, k, m;
	if(parent[i] > parent[j]){
		temp = parent[i];
		for(k = 0; k < n; k++){
			if(parent[k] == temp){
				parent[k] = parent[j];
			}
		}
	}else if(parent[i] < parent[j]){
		temp = parent[j];
		for(k = 0; k < n; k++){
			if(parent[k] == temp){
				parent[k] = parent[i];
			}
		}
	}for(k = 0; k < n; k++){
		for(m = 0; m < n; m++){
			if(k == 0 && m == 0){
				printf(" {%d",k);
			}else if(k == m && k == parent[m] && parent[k] == m){
				printf("} {%d",k);
			}else if(parent[m] == k && parent[k] == k){
				printf(",%d",m);
			}else if((k == n-1) && (m == n-1)){
				printf("}\n");
			}
		}
	}printf("}\n");
}

int main(){
	int n, i, a, b, j;
	char step;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		parent[i] = i;
	}while(scanf("%c",&step) == 1){
		if(step == '-1'){
			break;
		}else if(step == 'U'){
			scanf("nion(%d,%d)",&a,&b);
			printf("Union(%d,%d):",a,b);
			Union(a,b,n);
		}else if(step == 'F'){
			scanf("ind(%d), Find(%d)",&a,&b);
			printf("Find(%d), Find(%d): ",a,b);
			Find(a,b);
		}
	}return 0;
}

/*
10
Union(1,4)
Find(1), Find(4)
Union(2,3)
Union(4,5)
Union(0,6)
Find(1), Find(5)
Find(4), Find(6)
Union(7,0)
Union(0,8)
Union(9,1)
Find(2), Find(5)
Find(4), Find(9)
Find(7), Find(6)
-1
*/
