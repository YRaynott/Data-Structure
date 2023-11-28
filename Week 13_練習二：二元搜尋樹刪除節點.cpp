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

int compare(treePointer ptr, int n){
	if(ptr){
		if(ptr->data == n){
			return 0;
		}else{
			if(compare(ptr->leftChild,n) && compare(ptr->rightChild,n)){
				return 1;
			}else if(compare(ptr->leftChild,n)){
				return compare(ptr->rightChild,n);
			}else if(compare(ptr->rightChild,n)){
				return compare(ptr->leftChild,n);
			}
		}
	}return 1;
}

treePointer search(treePointer ptr, int n){
	if(ptr){
		if(ptr->data == n){
			return ptr;
		}else{
			search(ptr->rightChild,n);
			search(ptr->leftChild,n);
		}
	}
}

void delet(treePointer *root, int n){
	int max;
	treePointer x, tmp, y, z;
	x = (treePointer)malloc(sizeof(*x));
	tmp = (treePointer)malloc(sizeof(*tmp));
	y = (treePointer)malloc(sizeof(*y));
	z = x = *root;
	while(x){					//z為要刪除的父節點 
		if(x->data == n){
			break;
		}if(n < x->data){
			z = x;
			x = x->leftChild;
		}else{
			z = x;
			x = x->rightChild;
		}
	}y = x;					//x目前為要刪除的點
	if(x->leftChild){
		tmp = x->leftChild;
	}else if(x->rightChild){
		tmp = x->rightChild;
	}else{
		if(x == z->leftChild){
			z->leftChild = NULL;
			return;
		}else if(x == z->rightChild){
			z->rightChild = NULL;
			return;
		}
	}max = tmp->data;
	if(!(x->leftChild)||!(x->rightChild)){
		if(z->data < max){
			z->rightChild = tmp;
			return;
		}else{
			z->leftChild = tmp;
			return;
		}
	}while(tmp->rightChild){
		if(tmp->rightChild->data > max){
			y = tmp;
			tmp = tmp->rightChild;
			max = tmp->data;
		}
	}
	if(tmp->leftChild){
		x->data = tmp->data;
		tmp = tmp->leftChild;
	}else{
		if(tmp == y->rightChild){
			y->rightChild = tmp->leftChild;
		}else{
			y->leftChild = tmp->leftChild;
		}
		x->data = tmp->data;
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
	char symbol;
	treePointer x;
	while(scanf("%d%c",&n,&symbol)==2){
		if(symbol != ' '){
			break;
		}else{
			insert(&root,n);
		}
	}insert(&root,n);
	printf("Binary search tree (before):\n");
	preorder(root);
	printf("\n");
	while(scanf("%d",&n)==1){
		if(compare(root,n)){
			printf("no %d\n",n);
		}else{
			delet(&root,n);
		}
	}printf("Binary search tree (after):\n");
	preorder(root);
	printf("\n");
	return 0;
}

/*
20 15 22 25 18 12 10 24
25 40 12 15 20 3

1 2 3 4 5
3 6
*/
