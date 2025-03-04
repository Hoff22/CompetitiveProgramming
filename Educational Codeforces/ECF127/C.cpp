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

int of = 0;



void solve(){
	long long n, x;
	scanf("%lld %lld", &n, &x);

	vector<long long> a(n+1);
	vector<long long> sum(n+1);
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a.begin(), a.end());
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
	}

	int s;
	for(s = 0; s <= n; s++){
		if(sum[s] > x) break;
	}
	s--;

	long long aux[N+1];
	for(int i = 1; i <= n; i++){
		aux[i] = (x - sum[i]) / i + 1;
	}

	long long ans = 0;
	long long last = 0;
	for(int i = s; i >= 1; i--){
		ans += (aux[i] - last) * i;
		last = aux[i];
	}

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