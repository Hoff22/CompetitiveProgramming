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
	int n, k;
	scanf("%d %d", &n, &k);

	vector<long long> a(n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);		
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < n; i++){
		if(k and a[i] < 0){
			a[i] *= -1;
			k--;
		}
	}
	if((k % 2) and k){
		sort(a.begin(), a.end());
		a[0] *= -1;
	}
	// 5 2
	// 2 4 6
	// -4 -1 20 20
	long long ans = 0;
	for(int i : a){
		ans += i;
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