#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node *treePointer;
struct node{
	char data[10];
	treePointer leftChild, rightChild;
};

treePointer root = NULL;

void insert(treePointer *root, char data[], char left[], char right[]){
	int num;
	char check[10];
	treePointer x, tmp, tl, tr;
	tmp = (treePointer)malloc(sizeof(*tmp));
	tl = (treePointer)malloc(sizeof(*tl));
	if(right != 0){
		tr = (treePointer)malloc(sizeof(*tr));
		strcpy(tr->data,right);
		tr->leftChild = NULL;
		tr->rightChild = NULL;
	}strcpy(tmp->data,data);
	strcpy(tl->data,left);
	tmp->leftChild = NULL;
	tmp->rightChild = NULL;
	tl->leftChild = NULL;
	tl->rightChild = NULL;
	x = (treePointer)malloc(sizeof(*x));
	x = *root;
	if(*root){
		while(x){
			strcpy(check,x->data);
			if(!strcmp(check,data)){
				if((left[2]-48)%2){				//奇數是左節點，偶數是右節點 
					x->leftChild = tl;
				}else{
					x->rightChild = tl;
				}if(right != 0){
					if((right[2]-48)%2){
						x->leftChild = tr;
					}else{
						x->rightChild = tr;
					}
				}break;
			}else{
				if(*check == 'r'){
					if((data[2]-48) <= pow(2,(data[1]-48)-1)){
						x = x->leftChild;
					}else{
						x = x->rightChild;
					}
				}else if((data[1]-48) == (check[1]-48)+1){
					if((data[2]-48)%2){
						x = x->leftChild;
					}else{
						x = x->rightChild;
					}
				}else{
					if((data[2]-48) <= pow(2,(check[1]-48)-1)){
						x = x->leftChild;
					}else{
						x = x->rightChild;
					}
				}
			}
		}
	}else{
		if((left[2]-48)%2){
			tmp->leftChild = tl;
		}else{
			tmp->rightChild = tl;
		}if(right != 0){
			if((right[2]-48)%2){
				tmp->leftChild = tr;
			}else{
				tmp->rightChild = tr;
			}
		}*root = tmp;
	}
}

void preorder(treePointer ptr){
	if(ptr){
		printf("%s ",ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		printf("%s ",ptr->data);
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%s ",ptr->data);
	}
}

void print(treePointer ptr){
	printf("Preorder: ");
	preorder(ptr);
	printf("\nInorder: ");
	inorder(ptr);
	printf("\nPostorder: ");
	postorder(ptr);
	printf("\nThe balance factor is ");
}

int height(treePointer root){
	int left, right;
	if(root == NULL){
		return 0;
	}
	left = height(root->leftChild);
	right = height(root->rightChild);
	if(left > right){
		return left+1;
	}else{
		return right+1;
	}
}

int main(){
	int i, j;
	char data[10], left[10], right[10];
	scanf("%s",data);
	while(*data != '0'){
		scanf("%s%s",left,right);
		if(left[1]==right[1] && left[2] < right[2]){
			insert(&root,data,left,right);
			scanf("%s",data);
		}else{
			insert(&root,data,left,0);
			strcpy(data,right);
		}
	}print(root);
	i = height(root->leftChild);
	j = height(root->rightChild);
	if(i >= j){
		printf("%d\n",i-j);
	}else{
		printf("%d\n",j-i);
	}
	return 0;
}

/*
r n11 n12
n11 n21 n22
n12 n23
n21 n31 n32
n22 n33
n33 n45 n46
0

				r
		 n11		n12
	n21 	n22  n23
n31  n32  n33
		n45  n46
*/
