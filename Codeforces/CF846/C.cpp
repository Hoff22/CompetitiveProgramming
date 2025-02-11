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

	priority_queue<int> c;
	priority_queue<int> pq;

	vector<int> x(n+1, 0);

	for(int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		x[a]++;
	}

	for(int i = 1; i <= n; i++){
		if(x[i]) pq.push(x[i]);
	}

	for(int i = 1; i <= m; i++){
		int a;
		scanf("%d", &a);
		c.push(a);
	}

	long long ans = 0;
	while(pq.size() and c.size()){
		int val = pq.top();
		pq.pop();

		int max_table = c.top();
		c.pop();

		if(val > max_table){
			val -= max_table;

			pq.push(val);

			ans += max_table;
		}
		else{

			ans += val;

		}

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