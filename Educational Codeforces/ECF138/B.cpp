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

	vector<long long> a;
	vector<long long> b;

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		b.push_back(x);
	}

	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += a[i] + b[i];
	}

	ans -= b[0];

	printf("%lld\n", ans);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}