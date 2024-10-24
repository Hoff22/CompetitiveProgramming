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
	vector<long long> b(n+1);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &b[i]);
	}

	vector<long long> ac(n+1, 0);
	for(int i = 1; i <= n; i++){
		ac[i] = ac[i-1] + b[i];
	}

	vector<vector<long long>> h(n+1, vector<long long>());

	for(int i = 1; i <= n; i++){
		auto p = lower_bound(ac.begin()+i, ac.end(), a[i]+ac[i-1]);
		if(p != ac.end()){
			int j = (int)(p-ac.begin());
			h[j].push_back(a[i] + ac[i-1] - ac[j-1]);
		}
	}

	vector<long long> ans(n+1, 0);

	int z = 0;
	for(int i = 1; i <= n; i++){
		ans[i] = b[i] * (i-z);

		for(long long v : h[i]){
			ans[i] -= b[i];
			ans[i] += v;
			z++;
		}


	}

	for(int i = 1; i <= n; i++){
		printf("%lld ", ans[i]);
	}
	printf("\n");

}

/*

6 * 13  == 18


 6  6  6  == 18
10 20 15  == 45

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