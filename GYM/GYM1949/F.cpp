#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

constexpr int N = 2000000;

typedef long long ll;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> v(m+1,{0,0});
	vector<vector<int>> a(n+1, vector<int>());
	vector<int> order;

	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int u;
			cin >> u;
			a[i].push_back(u);
		}
		order.push_back(i);
	}

	sort(order.begin(), order.end(), [&](int i, int j){return a[i].size() > a[j].size();});

	int t = 1;
	for(int i : order){
		for(int j : a[i]){
			if(v[a[i][0]].fi != v[j].fi){
				cout << "YES" << endl;
				cout << i << " " << ((v[a[i][0]].fi > v[j].fi) ? v[a[i][0]].se : v[j].se) << endl;
				return 0;
			}
		}
		for(int j : a[i]) v[j] = {t,i};
		t++;
	}

	cout << "NO" << endl;

	return 0;

}