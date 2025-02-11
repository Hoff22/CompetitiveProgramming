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

void solve(){
	int n, p;
	scanf("%d %d", &n, &p);
	vector<int> a(n);
	set<pair<int,int>> idx;
	vector<bool> seen(n, false);
	long long ans = 0;

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		idx.insert({a[i], i});
	}

	for(auto e : idx){

		int mn = e.first;
		int i = e.second;
		//printf("\t%d\n", mn);

		if(mn >= p) break;

		for(; i < n-1; i++){
			if(seen[i]) break;
			if(__gcd(mn, a[i+1]) == mn){
				ans += mn;
				seen[i] = true;
			}
			else break;
		}

		i = e.second-1;
		for(; i >= 0; i--){
			if(seen[i]) break;
			if(__gcd(mn, a[i]) == mn){
				ans += mn;
				seen[i] = true;
			}
			else break;
		}
	}

	for(int i = 0; i < n-1; i++){
		if(seen[i] == 0) ans += p;
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