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

int ans[N+1];

void solve(int q){
	int n;
	//int ans = 0;
	scanf("%d", &n);

	char s[N+1];

	for(int i = 1; i <= n; i++){
		scanf(" %c", &s[i]);
	}

	char last = 0;
	for(int i = 1; i <= n; i++){
		if(last < s[i]){
			ans[i] = ans[i-1] + 1;
		}
		else{
			ans[i] = 1;
		}
		last = s[i];
	}

	printf("Case #%d: ", q);
	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}