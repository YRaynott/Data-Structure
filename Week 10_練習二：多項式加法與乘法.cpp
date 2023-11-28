#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode *polyPointer;
struct polyNode{
	int coef;
	int expon;
	polyPointer link;
};

polyPointer a = NULL;
polyPointer b = NULL;

void f_insert(polyPointer *first, int n, int m){
	polyPointer temp;
	temp = (polyPointer)malloc(sizeof(*temp));
	temp->coef = n;
	temp->expon = m;
	if(*first){
		temp->link = *first;
	}else{
		temp->link = NULL;
	}*first = temp;
}

void a_insert(polyPointer *first, int n, int m){
	polyPointer temp, x;
	temp = (polyPointer)malloc(sizeof(*temp));
	temp->coef = n;
	temp->expon = m;
	temp->link = NULL;
	if(*first){
		x = (polyPointer)malloc(sizeof(*x));
		x = *first;
		while(x->link){
			x = x->link;
		}x->link = temp;
	}else{
		*first = temp;
	}
}

void sort(polyPointer *first, int co, int expn){
	int n;
	polyPointer x, temp;
	x = (polyPointer)malloc(sizeof(*x));
	x = *first;
	temp = (polyPointer)malloc(sizeof(*temp));
	temp->coef = co;
	temp->expon = expn;
	temp->link = NULL;
	if(expn > x->expon){
		f_insert(first,co,expn);
		return;
	}while(x->link){
		if(expn > x->link->expon){
			break;
		}else{
			x = x->link;
		}
	}temp->link = x->link;
	x->link = temp;
}

void print(polyPointer first){
	printf(" %dx^%d",first->coef,first->expon);
	first = first->link;
	for(;first; first = first->link){
		if(first->coef != 0){
			if(first->expon > 1){
				printf(" + %dx^%d",first->coef,first->expon);
			}else if(first->expon == 1){
				printf(" + %dx",first->coef);
			}else{
				printf(" + %d",first->coef);
			}
		}
	}printf("\n");
}

void padd(polyPointer a, polyPointer b){
	polyPointer c = NULL;
	while(a && b){
		if(a->expon == b->expon){
			a_insert(&c,a->coef+b->coef,a->expon);
			a = a->link;
			b = b->link;
		}else if(a->expon > b->expon){
			a_insert(&c,a->coef,a->expon);
			a = a->link;
		}else{
			a_insert(&c,b->coef,b->expon);
			b = b->link;
		}
	}while(a){
		a_insert(&c,a->coef,a->expon);
		a = a->link;
	}while(b){
		a_insert(&c,b->coef,b->expon);
		b = b->link;
	}
	printf("add =");
	print(c);
}

void pmul(polyPointer a, polyPointer b){
	polyPointer c = NULL;
	polyPointer i, j, k;
	for(; a; a = a->link){
		for(i = b; i; i = i->link){
			a_insert(&c,a->coef*i->coef,a->expon+i->expon);
		}
	}for(j = c; j->link; j = j->link){
		for(i = j->link, k = j; i; k = i, i = i->link){
			if(j->expon == i->expon){
				j->coef += i->coef;
				i->coef = 0;
			}else if(c->expon < i->expon){
				int tmpc, tmpe;
				tmpc = j->coef;
				j->coef = i->coef;
				i->coef = tmpc;
				tmpe = j->expon;
				j->expon = i->expon;
				i->expon = tmpe;
			}
		}
	}for(i = c; i->link; i = i->link){
		for(j = i->link; j; j = j->link){
			if(i->expon < j->expon){
				int tmpc, tmpe;
				tmpc = j->coef;
				j->coef = i->coef;
				i->coef = tmpc;
				tmpe = j->expon;
				j->expon = i->expon;
				i->expon = tmpe;
			}
		}
	}
	printf("mult =");
	print(c);
}

int main(){
	int n, m, t = 2;
	int l = 0;
	while(scanf("%d",&n)){
		if(t <= 0){
			break;
		}else if(n == -1){
			t--;
			l = 0;
		}else if(t == 2){
			scanf("%d",&m);
			if(l == 0){
				f_insert(&a,n,m);
				l++;
			}else{
				sort(&a,n,m);
			}
		}else if(t == 1){
			scanf("%d",&m);
			if(l == 0){
				f_insert(&b,n,m);
				l++;
			}else{
				sort(&b,n,m);
			}
		}
	}print(a);
	print(b);
	padd(a,b);
	pmul(a,b);
	return 0;
}

/*
3 3
1 1
2 2
4 4
-1
2 2
3 3
1 0
-1
*/
