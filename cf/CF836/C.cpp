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

int n, x;
vector<long long> v;

void solve(){
	scanf("%d %d", &n, &x);

	if(n % x != 0) {
		printf("-1\n");
		return;
	}

	v.assign(n+1, 0ll);

	int d = n/x;

	vector<int> factors;

	for(int i = 2; i * i <= d; i++){
		while(d % i == 0){
			factors.push_back(i);
			d /= i;
		}		
	}
	if(d > 1) factors.push_back(d);

	int cur = x;
	for(int i : factors){
		v[cur] = cur * i; 
		cur = cur * i;
	}

	v[1] = x;
	v[n] = 1;
	for(long long i = 1; i <= n; i++){
		if(v[i] == 0){
			v[i] = i;
		}
	}

	for(long long i = 1; i<= n; i++){
		printf("%lld ", v[i]);
	}
	printf("\n");
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