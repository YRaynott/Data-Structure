#include <stdio.h>
#define MAX_TERMS 100
#define COMPARE(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1 )

typedef struct{
    float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;

void print(int start, int end){
	int i;
	printf("%.2fx^%d", terms[start].coef, terms[start].expon);
	for(i = start + 1; i <= end; i++){
		if(terms[i].expon > 1){
			printf("%+.2fx^%d", terms[i].coef, terms[i].expon);
		}else if(terms[i].expon == 1){
			printf("%+.2fx", terms[i].coef);
		}else{
			printf("%+.2f\n", terms[i].coef);
		}
	}
}

void attach(float coefficient, int exponent){
    /* add a new term to the polynomial */
    /*if(avail > MAX_TERMS){
        fprintf(stderr, ¡§Too many terms in the polynomial\n¡¨);
		exit(1);
    }*/
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}

void padd(int starta, int enda, int startb, int endb, int startd, int endd){
    float coefficient;
    startd = avail;
	while((starta <= enda) && (startb <= endb)){
		switch(COMPARE(terms[starta].expon, terms[startb].expon)){
			case -1:
				attach(terms[startb].coef, terms[startb].expon);
				startb++;
				break;
			case 0:
				coefficient = terms[starta].coef + terms[startb].coef;
				if(coefficient != 0){
					attach(coefficient,terms[starta].expon);
				}
				starta++;
				startb++;
				break;
			case 1:
				attach(terms[starta].coef, terms[starta].expon);
				starta++;
		}
    }for(; starta <= enda; starta++){
    	attach(terms[starta].coef, terms[starta].expon);
	}for(; startb <= endb; startb++){
       	attach(terms[startb].coef, terms[startb].expon);
	}endd = avail - 1;
	print(startd,endd);
}

int main(){
	int starta = 0;
	int n, i;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%f",&terms[i].coef);
		scanf("%d",&terms[i].expon);
	}int enda = i - 1, startb = i;
	scanf("%d",&n);
	for(i = startb; i < startb + n; i++){
		scanf("%f",&terms[i].coef);
		scanf("%d",&terms[i].expon);
	}int endb = i - 1;
	avail = i;
	print(starta,enda);
	print(startb,endb);
	padd(starta, enda, startb, endb,0,0);
	return 0;
}

/*
4
5.5 50000
2 300
9 2
25 0
5
8 400
-2 300
5 2
-4 1
7 0
*/
