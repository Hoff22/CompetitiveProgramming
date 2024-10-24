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
	int n;
	scanf("%d", &n);

	vector<long long> v(n);
	for(int i = 0; i < n; i++) scanf("%lld", &v[i]);

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	long long ans = v[0];
	vector<long long> c(n);

	for(int i = 1; i < n-1; i++) c[0] += (v[0] - v[i]);
	for(int i = 1; i < n-1; i++) c[i] = c[i-1] - (v[i-1] - v[i])*(n-i-1);
	for(int i = 0; i < n-1; i++) ans -= (v[i] + c[i]);

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