#include <stdio.h>

void horizontal(int arr[20][20], int n){
	int i, j, temp, t = n - 1;
	for(i = 0; i < n; i++){
		for(j = 0; j < n / 2; j++){
			temp = arr[i][j];
			arr[i][j] = arr[i][t];
			arr[i][t] = temp;
			t -= 1;
		}t = n - 1;
	}
}

void vertical(int arr[20][20], int n){
	int i, j, temp, t = n - 1;
	for(j = 0; j < n; j++){
		for(i = 0; i < n / 2; i++){
			temp = arr[i][j];
			arr[i][j] = arr[t][j];
			arr[t][j] = temp;
			t -= 1;
		}t = n - 1;
	}
}

void diagonal(int arr[20][20], int n){
	int i, j, temp, t = n - 1;
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
}

int main(){
	int n, arr[20][20]={0};
	char m, ch[20]={0};
	scanf("%d%*c",&n);
	int i, j, num = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			num += 1;
			arr[i][j] = num;
		}
	}int h, d, v = 0;
	while(scanf("%c",&m)!=EOF){
		switch(m){
			case 'H':
				h++;
				if(h%2==0){
					h = 0;
				}break;
			case 'V':
				v++;
				if(v%2==0){
					v = 0;
				}break;
			case 'D':
				d++;
				if(d%2==0){
					d = 0;
				}break;
		}
	}if(h!=0){
		horizontal(arr, n);
	}if(v!=0){
		vertical(arr, n);
	}if(d!=0){
		diagonal(arr, n);
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n - 1; j++){
			printf("%d ",arr[i][j]);
		}printf("%d\n",arr[i][j]);
	}
	return 0;
}

/*
4
HVDVHDHVH
*/
