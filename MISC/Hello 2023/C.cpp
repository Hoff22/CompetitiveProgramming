
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
	long long n, k;
	scanf("%lld %lld", &n, &k);

	vector<long long> a(n+1);
	vector<long long> pref(n+1, 0);

	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		pref[i] = pref[i-1] + a[i];
	}

	// debug
	// for(long long i = 1; i <= n; i++){
	// 	printf("%lld%c", pref[i], " \n"[i==n]);
	// }

	long long ans = 0;
	priority_queue<pair<long long,long long>> pq;
	
	if(a[k] > 0) pq.push({a[k], k});

	for(long long i = k-1; i >= 1; i--){

		while(pref[i] < pref[k]){
			long long p = pq.top().se;
			pq.pop();

			pref[k] -= 2*a[p];
			a[p] *= -1;
			ans++;
		}

		if(a[i] > 0) pq.push({a[i], i});
	}

	for(long long i = 1; i <= n; i++){
		pref[i] = pref[i-1] + a[i];
	}

	while(!pq.empty()) pq.pop();

	for(long long i = k+1; i <= n; i++){
		if(a[i] < 0) pq.push({-a[i], i});

		while(pref[i] < pref[k]){
			long long p = pq.top().se;
			pq.pop();

			pref[k] -= (-2*a[p]);
			a[p] *= -1;
			ans++;
		}

	}

	// debug
	// for(long long i = 1; i <= n; i++){
	// 	printf("%lld%c", a[i], " \n"[i==n]);
	// }
	// for(long long i = 1; i <= n; i++){
	// 	printf("%lld%c", pref[i], " \n"[i==n]);
	// }

	printf("%lld\n", ans);
}


/*
  1  2 -1  2  1  1 -3

           V
  1  3  2  4  5  6  3

  1 -1 -2  0        

*/

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