#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1];

int main(){
	
	int n, t;
	int A, B;
	scanf("%d %d", &n, &t);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	
	A = B = 0;

	int sum = 0;

	for(int i = 1; i <= n; i++){
		sum += a[i];
		A++;
		if(sum > t) break;
	}

	sum = 0;
	for(int i = n; i > 0; i--){
		sum += a[i];
		B++;
		if(sum > t) break;
	}

	

	if(A > B) printf("Yan\n");
	else if(A < B) printf("Nathan\n");
	else printf("Empate\n");
	

    return 0;

}