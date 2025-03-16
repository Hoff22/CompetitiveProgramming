#include <bits/stdc++.h>

#define N 100
#define MAX 1000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define fi first
#define se second


using namespace std;


// 	ECF 111 B //////////////////////////////////////////////////


void go(){
	
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);


	int cnt = 1;
	char last;
	for(int i = 1; i <= n; i++){
		char x;
		scanf(" %c", &x);
		if(i>1 and last != x) cnt++;
		last = x;
	}

	if(b >= 0 or n == 1){
		printf("%d\n", n*b + n*a);
		return;
	}

	printf("%d\n", (cnt/2 + 1)*b + n*a);
}
int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		go();
	}
    return 0;

}