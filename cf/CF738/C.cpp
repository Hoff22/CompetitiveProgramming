#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n;
	scanf("%d", &n);

	int last = 0;
	int f = 0;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);

		if(i == 1) last = x;
		if(last == 0 and x == 1 and !f){
			printf("%d ", n+1);
			f = 1;
		}
		printf("%d ", i);

		last = i;
	}
	printf("\n");
}


int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}