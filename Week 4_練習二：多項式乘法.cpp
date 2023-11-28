#include <stdio.h>
#define MAX_TERMS 100
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

typedef struct{
    float coef;
	int expon;
}polynomial;
polynomial a[MAX_TERMS];
polynomial b[MAX_TERMS];
polynomial c[MAX_TERMS];

void print(polynomial t[], int end){
	int i;
	printf("%.2fx^%d", t[0].coef, t[0].expon);
	for(i = 1; i < end; i++){
		if(t[i].expon > 1){
			printf("%+.2fx^%d", t[i].coef, t[i].expon);
		}else if(t[i].expon == 1){
			printf("%+.2fx", t[i].coef);
		}else{
			printf("%+.2f", t[i].coef);
		}
	}printf("\n");
}

void pmult(int na, int nb, int nc){
    int i, j;
    nc = 0;
    for(i = 0; i < na; i++){
    	for(j = 0; j < nb; j++){
    		c[nc].coef = a[i].coef * b[j].coef;
    		c[nc++].expon = a[i].expon + b[j].expon;
		}
	}int tempi, t;
	float tempf;
	for(i = 0; i < nc - 1; i++){
		for(j = i + 1; j < nc; j++){
			if(c[i].expon < c[j].expon){
				SWAP(c[i].coef, c[j].coef, tempf);
				SWAP(c[i].expon, c[j].expon, tempi);
			}else if(c[i].expon == c[j].expon){
				c[i].coef += c[j].coef;
				for(t = j; t < nc - 1; t++){
					c[t].coef = c[t + 1].coef;
					c[t + 1].coef = 0;
					c[t].expon = c[t + 1].expon;
					c[t + 1].expon = 0;
				}nc--;
			}
		}
	}
	print(c,nc);
}

int main(){
	int n, i;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%f",&a[i].coef);
		scanf("%d",&a[i].expon);
	}int na = i;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%f",&b[i].coef);
		scanf("%d",&b[i].expon);
	}int nb = i;
	print(a,na);
	print(b,nb);
	pmult(na,nb,0);
	return 0;
}

/*
4
3.5 50000
2 3
9 2
25 0
5
7 400
-2 300
5 2
-4 1
7 0
*/ 
