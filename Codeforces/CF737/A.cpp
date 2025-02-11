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

	long long sum = 0;
	long long mx = -INF;
	for(int i = 0; i < n; i++){
		long long x;
		scanf("%lld", &x);
		sum += x;
		mx = max(mx, x);
	}

	printf("%.12lf\n", 1.0*(sum-mx)/(n-1) + mx);

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}