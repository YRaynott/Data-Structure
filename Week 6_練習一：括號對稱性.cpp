#include <stdio.h>
#include <string.h>

int main(){
	int n, i = 0;
	char str[30] = {0};
	while(scanf("%s",&str) != EOF){
		if(strcmp(str,"end") == 0){
			break;
		}else{
			if(str[0] != '('){
				printf("-1\n");
				break;
			}i++;
			n++;
			while(str[i] != 0){
				if(str[i] == '('){
					n++;
				}else{
					n--;
				}i++;
			}if(n == 0){
				printf("1\n");
			}else{
				printf("-1\n");
			}
		}
	}
	return 0;
}
/*
(()())
(()))
)(
end
*/
