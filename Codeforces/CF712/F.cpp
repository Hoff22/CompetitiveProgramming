#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1];
int b[N+1];

// min has to have at least n+1 as back
// max has to have at most min+(n)
// 1     10
// 9     1 
int main(){
	
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}

	for(int i = 0; i < n; i++){

	}

    return 0;

}
/*
8 4  0 4
7 1  1
4 2  3
3 0  1
2 3  3
0 1  2


*/