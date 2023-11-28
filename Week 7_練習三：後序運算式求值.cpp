#include <stdio.h>
#include <stdlib.h>

int main(){
	char op;
	char q[100] = {0};
	int num[100] = {0};
	int top = 0, i;
	while(scanf("%s",q)!=EOF){
		i = 0;
		num[top] = 0;
		while(q[i] >= '0' && q[i] <= '9'){
			num[top] = num[top]*10 + (q[i] - '0');
			i++;
		}if(i != 0){
			top++;
		}
		if(q[0] == '+'){
			num[top-2] = num[top-2]+num[top-1];
			num[top-1] = 0;
			top--;
		}else if(q[0] == '-'){
			num[top-2] = num[top-2]-num[top-1];
			num[top-1] = 0;
			top--;
		}else if(q[0] == '*'){
			num[top-2] = num[top-2]*num[top-1];
			num[top-1] = 0;
			top--;
		}else if(q[0] == '/'){
			num[top-2] = num[top-2]/num[top-1];
			num[top-1] = 0;
			top--;
		}else if(q[0] == '%'){
			num[top-2] = num[top-2]%num[top-1];
			num[top-1] = 0;
			top--;
		}
	}printf("%d\n",num[0]);
	return 0;
}

/*
3 5 * 5 +
2 5 % 5 +
6 2 / 3 - 4 5 * + 7 %
1024 1024 * 1024 512 / *
1 2 3 4 5 * + % -
*/
