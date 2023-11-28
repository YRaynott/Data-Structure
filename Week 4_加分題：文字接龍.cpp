#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n, i;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		char a[1000] = {0};
		scanf("%s",a);
		int j = 0, k, m;
		char temp;
		int len;
		len = strlen(a) - 1;
		for(j = 0; j < len + 1; j++){
			switch(a[j]){
				case 'a':
					for(k = j + 1, m = 0; k <= (len-j)/2+j; k++, m++){
						temp = a[k];
						a[k] = a[len - m];
						a[len - m] = temp;
					}//printf("a = %s\n",a);
					break;
				case 'b':
					for(k = j + 1, m = 1; k < len + 1; k++, m++){
						a[len + m] = a[k];
					}//printf("b = %s\n",a);
					len = strlen(a) - 1;
					break;
				case 'c':
					a[j + 1] = a[j + 2] = 0;
					for(k = j + 1; k < len + 1; k++){
						a[k] = a[k + 2];
						a[k + 2] = 0;
					}//printf("c = %s\n",a);
					len = strlen(a) - 1;
					break;
			}
		}printf("%s\n",a);
	}
	return 0;
}

/*
5
about
peter
fractional
acebf
aliceisnotaboy
*/
