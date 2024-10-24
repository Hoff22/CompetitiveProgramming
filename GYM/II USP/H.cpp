#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define FLOOR 0
#define FOOT 1
#define CHAIN 2
#define IMPAR 1

using namespace std;

int a[3][N+1];

int main(){
	
	int n;
	scanf("%d", &n);

	for(int j = 0; j < 3; j++){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[j][i]);
		}
	}

	long double d1 = 0;
	for(int i = 0; i < n; i++){
		d1 += (a[FLOOR][i] - a[FOOT][i]) * (a[FLOOR][i] - a[FOOT][i]);
	}
	d1 = sqrt(d1);

	long double d2 = 0;
	for(int i = 0; i < n; i++){
		d2 += (a[FLOOR][i] - a[CHAIN][i]) * (a[FLOOR][i] - a[CHAIN][i]);
	}
	d2 = sqrt(d2);

	if(d1 > d2){
		printf("MaratonIME\n");
	}
	else{
		printf("Yan\n");
	}
	

    return 0;

}