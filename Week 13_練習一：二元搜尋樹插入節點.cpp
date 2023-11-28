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

void preorder(treePointer ptr){
	if(ptr){
		printf("%d ",ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

int main(){
	int n, t;
	while(scanf("%d",&n)!=EOF){
		insert(&root,n);
		preorder(root);
		printf("\n");
	}
	return 0;
}

/*
30 5 40 2
*/
