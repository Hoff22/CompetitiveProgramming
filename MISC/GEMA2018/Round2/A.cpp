#include <bits/stdc++.h>

#define N 1000
#define MAX 10000000000
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int a, b, c;

int main(){
	
	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", a/2 + b/2 + c/2);
	
	return 0;
}