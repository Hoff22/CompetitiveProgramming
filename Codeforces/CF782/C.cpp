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

long long n, a, b;

void solve(){
	scanf("%lld %lld %lld", &n, &a, &b);

	vector<int> x;
	x.push_back(0);
	for(int i = 0; i < n; i++){
		int y;
		scanf("%d", &y);
		x.push_back(y);
	}


	long long ans = 0;
	int cur = 0;
	for(int i = 1; i <= n; i++){
		ans += b * (x[i] - x[cur]);
		if(b * (x[i] - x[cur]) * (n - i) > a * (x[i] - x[cur])){
			ans += a * (x[i] - x[cur]);
			cur = i;
		}
	}

	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}