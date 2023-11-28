#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef struct{
	short int vert;
	short int horiz;
}offsets;
offsets move[4];

typedef struct{
	short int row;
	short int col;
	short int dir;
}element;
element stack[MAX_STACK_SIZE];

char maze[10][10] = {0};
int top = -1;

void push(element item){
	if(top >= MAX_STACK_SIZE){
		printf("Full\n");
	}else{
		stack[++top] = item;
	}
}

element pop(){
	if(top == -1){
		printf("Empty\n");
	}else{
		return stack[top--];
	}
}

void path(){
	int i, j, row, col, next_row, next_col, dir, found = 0;
	int mark[10][10] = {0};
	offsets move[4] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
	element position;
	mark[8][8] = 1;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			if(i == 0 || j == 0 || i == 9 || j == 9){
				mark[i][j] = 1;
			}
		}
	}top = 0;
	stack[0].row = stack[0].col = 8;
	stack[0].dir = 0;
	while(top > -1 && !found){
		position  = pop();
		row = position.row; col = position.col;
		dir = position.dir;
		while(dir < 4 && !found){
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if(next_row == 1 && next_col == 1){
				found = 1;
			}else if(maze[next_row][next_col] == '0' && mark[next_row][next_col] == 0){
				mark[next_row][next_col] = 1;
				position.row = row; position.col =col;
				position.dir = ++dir;
				push(position);
				maze[next_row][next_col] = 'G';
				if(maze[row][col] != 'G'){
					maze[row][col] = 'G';
				}
				row = next_row; col = next_col;
				dir = 0;
			}else{
				if(maze[next_row][next_col] != '1'){
					maze[row][col] = 'D';
				}
				++dir;
			}
		}
	}if(found){
		maze[8][8] = 'S';
		maze[1][1] = 'X';
		printf("YES\n");
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10 - 1; j++){
				printf("%c ",maze[i][j]);
			}printf("%c\n",maze[i][j]);
		}
	}else{
		printf("NO\n");
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				if(maze[i][j] == 'G'){
					maze[i][j] = 'D';
				}
			}
		}
		maze[8][8] = 'S';
		maze[1][1] = 'X';
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10 - 1; j++){
				printf("%c ",maze[i][j]);
			}printf("%c\n",maze[i][j]);
		}
	}
}

int main(){
	int i, j;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			scanf(" %c",&maze[i][j]);
		}
	}path();
	return 0;
}

/*
1 1 1 1 1 1 1 1 1 1
1 0 0 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1
1 1 0 0 0 0 0 0 0 1
1 1 1 0 0 1 1 1 0 1
1 1 1 0 0 0 1 1 0 1
1 1 1 0 1 0 0 0 0 1
1 1 1 0 1 1 1 0 1 1
1 1 1 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

1 1 1 1 1 1 1 1 1 1
1 0 0 1 1 1 1 1 0 1
1 1 0 1 1 1 1 1 0 1
1 1 0 0 0 0 0 0 0 1
1 1 1 0 0 1 1 1 0 1
1 1 1 0 0 0 1 1 0 1
1 1 1 0 1 0 0 0 0 1
1 1 1 0 1 1 1 0 1 1
1 1 1 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

1 1 1 1 1 1 1 1 1 1
1 0 0 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1
1 1 0 1 0 0 0 0 0 1
1 1 1 0 1 1 1 1 0 1
1 1 1 0 1 0 1 1 0 1
1 1 1 0 1 0 0 0 0 1
1 1 1 1 1 1 1 0 1 1
1 1 1 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
*/
