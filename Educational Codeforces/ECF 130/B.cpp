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



}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, q;
	scanf("%d %d", &n, &q);

	vector<int> p(n+1);

	for(int i = 0; i < n; i++){
		scanf("%d", &p[i+1]);
	}

	vector<long long> sum(n+1);
	sum[0] = 0;

	sort(p.begin(), p.end());

	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + p[i];
	}

	while(q--){

		int x, y;
		scanf("%d %d", &x, &y);

		long long ans = sum[n-x+y] - sum[n-x];

		printf("%lld\n", ans);

	}

//  1 2 3 4 5 6 7 8 9
//0 1 2 3 4 5 6 7 8 9

    return 0;

}