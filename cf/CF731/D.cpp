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

long long a[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	
	vector<long long> ans(n,0);
	for(int i = 1; i < n; i++){
		if((a[i] & a[i-1]) != a[i-1]){
			int x = a[i];
			x ^= ((1<<30)-1);
			x &= a[i-1];
			a[i] ^= x; 
			ans[i] = x;
		}
	}

	for(int i = 0; i < ans.size(); i++){
		printf("%lld ", ans[i]);
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