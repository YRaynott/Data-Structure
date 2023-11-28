#include <stdio.h>
#include <stdlib.h>

void print(int tree[], int n){
	int i;
	printf("%d",tree[1]);
	for(i = 2; i < n; i++){
		printf(" %d",tree[i]);
	}if(tree[i] != 0){
		printf(" %d\n",tree[i]);
	}else{
		printf("\n");
	}
}

int main(){
	int n, i, j = 1, m, k;
	int num;
	int tree[100] = {0};
	scanf("%d",&n);
	num = 0;
	while(1){
		for(i = 0; i < 3; i++){
			scanf("%d",&m);
			if(m == -1){
				print(tree,j);
				return 0;
			}if(num == 0){
				if(i == 0){
					tree[j] = m;
				}else if(i == 1){
					tree[2*j] = m;
				}else if(i == 2){
					tree[2*j+1] = m;
					num++;
					j = 2*j+1;
				}
			}else{
				if(i == 0){
					for(k = 1; k < j+1; k++){
						if(m == tree[k]){
							j = k;
							break;
						}
					}
				}else if(i == 1){
					tree[2*j] = m;
				}else if(i == 2){
					tree[2*j+1] = m;
					j = 2*j+1;
				}
			}
		}
	}
	return 0;
}

/*
6
1 2 3
3 4 0
4 5 6
-1

4
5 2 6
2 4 0
-1
*/
