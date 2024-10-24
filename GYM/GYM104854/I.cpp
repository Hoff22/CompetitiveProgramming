#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 200000;
constexpr int M = 1000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

#define sum(x) (((x)*(x)+(x))/2)

typedef long long ll;

void solve(){
	int k, w;
	cin >> k >> w;

	vector<int> ans(k+1,0);
	for(int i = 1; i <= k; i++){
		cin >> ans[i];
	}

	map<string,vector<pair<int,int>>> val;

	for(int i = 0; i < w; i++){
		string s; cin >> s;
		int n; cin >> n;

		for(int j = 0; j < n; j++){
			int id, v;
			cin >> id >> v;
			val[s].push_back({id,v});
		}
	}

	vector<string> rem;

	for(auto [s, v] : val){
		int good = 0;
		for(auto [id, u] : v){
			if(ans[id] == u) good = 1;
		}
		if(!good) rem.push_back(s);
	}

	for(string s : rem) val.erase(s);

	vector<string> res_s;
	vector<int> use(k+1,0);

	while(val.size()){
		int good = 1;
		
		for(auto [s,v] : val){
			good = 1;
			for(auto [id, u] : v){
				if(ans[id] != u and use[id] == 0) good = 0;
			}
			if(good){
				res_s.push_back(s);
				for(auto [id, u] : v){
					use[id] = 1;
				}
				val.erase(s);
				break;
			}
		}

		if(!good) break;
	}

	int sum = 0;
	for(int i = 1; i <= k; i++){
		sum += use[i];
		if(use[i] == 0 and ans[i] == 0) sum++;
	}

	if(sum == k){
		reverse(res_s.begin(), res_s.end());
		for(string s : res_s) cout << s << " ";
		cout << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
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