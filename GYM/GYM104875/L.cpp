#include <bits/stdc++.h>

#define MAX 10000000
#define E 0.0000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
#define pi 3.1415926535897932384626433

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<string,string>> guess;
	map<char,int> opt;

	for(int i = 0; i < n-1; i++){
		string s, res;
		cin >> s >> res;
		guess.push_back({s,res});
	}

	vector<set<char>> must(m, set<char>());
	vector<set<char>> cant(m, set<char>());

	for(auto [s, res] : guess){
		map<char,int> cnt;
		for(int i = 0; i < m; i++){
			if(res[i] == 'Y') cant[i].insert(s[i]);
			if(res[i] == 'G') must[i].insert(s[i]);
			if(res[i] == 'B') cnt[s[i]]++;
		}

		for(auto [c, k] : cnt){
			opt[c] = max(opt[c], k);
		}
	}

	vector<int> order(m);
	for(int i = 0; i < m; i++) order[i]=i;

	sort(order.begin(), order.end(), [&](int a, int b){return cant[a].size()>cant[b].size();});

	vector<char> ans(m, 0);

	for(int i : order){
		if(must[i].size()){
			ans[i] = *must[i].begin();
			opt[ans[i]]--;
		}
	}

	for(int i : order){
		if(ans[i] != 0){
			continue;
		}

		
	}

	cout << endl;
}