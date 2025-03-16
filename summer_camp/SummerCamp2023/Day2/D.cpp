#include <bits/stdc++.h>

#define N 100
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

int n;
vector<int> q;
vector<int> ans;
vector<long long> acc;

int dp[1000+1][10000+1];

int go(int i, int l){
	if(i == q.size()){
		return 0;
	}

	int r = n;
	if(i>0){
		r -= (acc[i-1] - (n-l));
	}

	if(dp[i][l] != -1) return dp[i][l];

	if(l - q[i] >= 0 and r - q[i] >= 0){
		return dp[i][l] = max(go(i+1, l-q[i]), go(i+1, l)) + 1;
	}
	if(l - q[i] >= 0){
		return dp[i][l] = go(i+1, l-q[i]) + 1;
	}
	if(r - q[i] >= 0){
		return dp[i][l] = go(i+1, l) + 1;
	}

	return 0;
}

void rec(int i, int l){

	if(i == q.size()) return;

	int r = n;
	if(i>0){
		r -= (acc[i-1] - (n-l));
	}

	if(l - q[i] >= 0 and r - q[i] >= 0){
		if(go(i+1, l-q[i]) > go(i+1, l)){
			ans.push_back(0);
			rec(i+1, l-q[i]);
		}
		else{
			ans.push_back(1);
			rec(i+1, l);
		}
		return;
	}

	if(l - q[i] >= 0){
		ans.push_back(0);
		rec(i+1, l-q[i]);
		return;
	}
	if(r - q[i] >= 0){
		ans.push_back(1);
		rec(i+1, l);
		return;
	}

	return;
}

void solve(){

	scanf("%d", &n);
	n *= 100;

	q.clear();
	ans.clear();

	memset(dp, -1, sizeof(dp));

	for(;;){
		int x;
		scanf("%d", &x);

		if(x == 0) break;

		q.push_back(x);
	}

	acc.assign(q.size(), 0);
	for(int i = 0; i < q.size(); i++){
		if(i == 0) acc[i] = q[i];
		else acc[i] = acc[i-1] + q[i];
	}

	int k = go(0, n);
	rec(0, n);

	printf("%d\n", k);

	for(int i = 0; i < k; i++){
		if(ans[i]){
			printf("port\n");
		}
		else{
			printf("starboard\n");
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
		if(t>0) printf("\n");
	}
    return 0;

}