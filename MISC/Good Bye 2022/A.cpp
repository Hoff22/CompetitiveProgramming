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
	int n, m;
	scanf("%d %d", &n, &m);

	priority_queue<long long, vector<long long>, greater<long long>> pq;

	for(int i = 0; i < n; i++){
		long long x;
		scanf("%lld", &x);

		pq.push(x);
	}


	for(int i = 0; i < m; i++){
		long long x;
		scanf("%lld", &x);

		pq.pop();
		pq.push(x);
	}

	long long sum = 0;

	while(!pq.empty()){
		sum += pq.top();
		pq.pop();
	}

	printf("%lld\n", sum);

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