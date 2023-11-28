#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
struct node{
	int data;
	treePointer leftChild, rightChild;
};

treePointer root = NULL;

void insert(treePointer *root, int n){
	treePointer x, tmp;
	tmp = (treePointer)malloc(sizeof(*tmp));
	tmp->data = n;
	tmp->leftChild = NULL;
	tmp->rightChild = NULL;
	if(*root){
		x = (treePointer)malloc(sizeof(*x));
		x = *root;
		while(x){
			if(tmp->data < x->data){
				if(!(x->leftChild)){
					x->leftChild = tmp;
					break;
				}else{
					x = x->leftChild;
				}
			}else{
				if(!(x->rightChild)){
					x->rightChild = tmp;
					break;
				}else{
					x = x->rightChild;
				}
			}
		}
	}else{
		*root = tmp;
	}
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
	int n, t;
	while(scanf("%d",&n)!=EOF){
		insert(&root,n);
	}t = height(root);
	printf("%d\n",t);
	return 0;
}

/*
1 7 5 8->3
1 7 5 8 6->4
5 2 6 7->3
5 2 6 7 1->3
*/
