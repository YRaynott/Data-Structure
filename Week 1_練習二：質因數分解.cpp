#include <stdio.h>

int main(){
	unsigned int n, i;
	int t = 0;
	scanf("%u",&n);
	i = 2;
	while(n > i){
		while(n % i == 0){
			n/=i;
			t++;
		}if(n == 1){
			if(t > 1){
				printf("%u^%d",i,t);
			}else if(t == 1){
				printf("%u",i);
			}
		}else{
			if(t > 1){
				printf("%u^%d * ",i,t);
			}else if(t == 1){
				printf("%u * ",i);
			}
		}i += 1;
		t = 0;
	}if(n <= i && n != 1){
		printf("%u",n);
	}printf("\n");
	return 0;
}
