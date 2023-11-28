#include <stdio.h>
#define MAX_EXPR_SIZE 100
typedef struct{
	int isp;
	int icp;
	char mark;
}precedence;
precedence stack[10];
char expr[MAX_EXPR_SIZE];
//int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
//int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
int top = 0;

int get_token(char op){
	switch(op){
		case '(': return 0;
		case ')': return 1;
		case '+': return 2;
		case '-': return 3;
		case '/': return 4;
		case '*': return 5;
		case '%': return 6;
		case '\0': return 7;
		case ' ': return 8;
		default : return 9;
	}
}

void postfix(){
	precedence stack[9] =  {{0,20,'('}, {19,19,')'}, {12,12,'+'}, {12,12,'-'}, {13,13,'/'}, {13,13,'*'}, {13,13,'%'}, {0,0,'\0'}};
	char a[50] = {0};
	int topa = 0;
	int token;
	for(token = get_token(expr[top]); token != 7; token = get_token(expr[top])){
		//printf("token = %d\n",token);
		//printf("a[topa] = %c, topa = %d\n",a[topa],topa);
		if(token == 9){
			printf("%c ",expr[top]);
			top++;
		}else if(token == 8){
			top++;
		}else if(token == 1){
			//printf("get')'\n");
			while(get_token(a[topa]) != 0){
				//printf("a[topa]=%c ,topa=%d\n",a[topa],topa);
				printf("%c ",a[topa]);
				a[topa] = 0;
				topa--;
			}a[topa] = 0;
			topa--;
			//pop();
		}else{
			//printf("token %d\n",get_token(a[topa]));
			while(stack[get_token(a[topa])].isp >= stack[token].icp && a[topa] != '('){
				printf("%c ",a[topa]);
				topa++;
			}//printf("push %c\n",expr[top]);
			a[++topa] = expr[top++];
			//push(token);
		}
	}while(a[topa - 2] != 0){
		printf("end\n");
		printf("%c ",a[topa]);
		topa++;
	}printf("%c\n",a[topa]);
} 

int main(){
	int n, i;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		gets(expr);
		//printf("%s\n",expr);
		postfix();
		expr[MAX_EXPR_SIZE] = {0};
	}
	return 0;
}

/*
4
4 * 5 + 2
( ( 2 + 3 ) * 3 - 5 ) / 2
( 1 + 3 ) * 2
( 2 * 3 + 5 ) * 9 / 3
*/
