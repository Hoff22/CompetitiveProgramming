#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 100000;
constexpr int M = 200000;
constexpr int MOD = 1000000007;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;

typedef long long ll;

void solve(){
	int n, m;
	cin >> n >> m;

	vector<int> p(n+1,0);
	vector<ll> d(n+1,INF);
	vector<tuple<int,int,ll>> e(m);

	for(int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		e[i] = {u,v,w};
	}

	d[1] = 0;

	int la = -1;
	for(int i = 1; i <= n; i++){
		la = -1;
		for(auto [u,v,w] : e){
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				p[v] = u;
				la = v;
			}
		}
	}

	if(la == -1){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		set<int> vis;
		vector<int> ans;
		while(vis.count(la) == 0){
			vis.insert(la);
			ans.push_back(la);
			la = p[la];
		}
		reverse(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
			if(ans[i] == p[ans[0]]) break;
		}
		cout << ans[0];
		cout << endl;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}
