#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nameNode *namePointer;
typedef struct priceNode *pricePointer;
struct nameNode{
	char product[20];
	namePointer linkn;
	pricePointer linkp;
};

struct priceNode{
	int price;
	pricePointer link;
};

namePointer nfirst = NULL;

void print(namePointer first){
	pricePointer x;
	x = (pricePointer)malloc(sizeof(*x));
    for(; first; first = first->linkn){
        printf("%s,",first->product);
        for(x = first->linkp; x; x = x->link){
        	printf("%d,",x->price);
		}printf("\n");
    }
}

void f_insert(pricePointer *first, int n){
	pricePointer temp;
	temp = (pricePointer)malloc(sizeof(*temp));
	temp->price = n;
	if(*first){
		temp->link = *first;
	}else{
		temp->link = NULL;
	}*first = temp;
}

void insertp(pricePointer *first, int pr){
	pricePointer x, temp;
	x = (pricePointer)malloc(sizeof(*x));
	temp = (pricePointer)malloc(sizeof(*temp));
	x = *first;
	temp->price = pr;
	temp->link = NULL;
	if(pr < x->price){
		f_insert(first,pr);
		return;
	}while(x->link){
		if(pr < x->link->price){
			break;
		}else{
			x = x->link;
		}
	}
	temp->link = x->link;
	x->link = temp;
}

void insert(namePointer *nfirst, int n){
	int i, p, t;
	char name[20];
	namePointer x, temp;
	pricePointer y;
	for(i = 0; i < n; i++){
		t = 0;
		scanf("%s",name);
		scanf("%d",&p);
		temp = (namePointer)malloc(sizeof(*temp));
		temp->linkn = NULL;
		y = (pricePointer)malloc(sizeof(*y));
		y->price = p;
		y->link = NULL;
		if(*nfirst){
			x = (namePointer)malloc(sizeof(*x));
			x = *nfirst;
			for(; x; x = x->linkn){
				if(strcmp(name,x->product) == 0){
					t++;
					insertp(&x->linkp,p);
					break;
				}
				if(!(x->linkn)){
					strcpy(temp->product,name);
					temp->linkp = y;
					x->linkn = temp;
					break;
				}
			}
		}else{
			strcpy(temp->product,name);
			temp->linkp = y;
			*nfirst = temp;
		}
	}
}

int main(){
	int n, i, price;
	char name[20];
	scanf("%d",&n);
	insert(&nfirst,n);
	print(nfirst);
	return 0;
}

/*
9
apple 100
DVD 141
book 50
DVD 41
car 30
B_S 41
DVD 200
Dvd 41
apple 9
*/
