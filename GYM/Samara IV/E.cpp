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

int main(){

	int n;
	scanf("%d", &n);

	vector<pair<int,int>> prs;
	pair<int,int> mx;
	for(int i = 0; i < n; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		prs.push_back({l,r});

		if(r > mx.se){
			mx = {l,r};
		}
		else if(r == mx.se and l < mx.fi){
			mx = {l,r};
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		int r = prs[i].se;

		if(r >= mx.fi) ans++;
	}
	
	printf("%d\n", ans);

    return 0;

}