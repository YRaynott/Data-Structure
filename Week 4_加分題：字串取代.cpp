#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_rpc(char *str, char *old, char *newc){
	int i;
	char a[strlen(str)];
	//�Na��sizeof(a)�e��0���N 
	memset(a,0,sizeof(a));
	for(i = 0; i < strlen(str); i++){
		if(!strncmp(str + i, old, strlen(old))){
			//�Nnewc�[�Ja 
			strcat(a, newc);
			i += strlen(old) - 1;
		}else{
			strncat(a, str + i, 1);
		}
	}strcpy(str,a);
	return str;
}

int main(){
	char p[100], q[100], r[100], s[100];
	gets(p);
	scanf("%s",q);
	scanf("%s",r);
	printf("%s\n",str_rpc(p,q,r));
	return 0;
}

/*
A boy picked a ball, and the ball was red.
ball
hat
*/
