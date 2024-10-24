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

	vector<long long> a(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}


	int s = 1;
	int ans = INF;
	while(s <= n){
		long long m = 0;
		for(int i = 1; i <= s; i++) m += a[i];

		int th = 0;
		int last = 0;
		long long cur = 0;
		for(int i = 1; i <= n; i++){
			cur += a[i];
			if(cur == m){
				th = max(th, i - last);
				last = i;
				cur = 0;
			}
		}

		if(last == n){
			ans = min(ans, th);
		}
		
		s++;
	}

	printf("%d\n", ans);
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