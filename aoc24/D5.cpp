// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
#include<set>

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define N 100

vector<int> g[N+1];
vector<int> order(100,101);
vector<int> in(100,0);

void solve(){
	vector<vector<int>> a;
	string s;

	set<pair<int,int>> seen;

	while(cin >> s){
		if(s[2] == '|'){
			int u, v;
			u = (s[0]-'0') * 10 + (s[1]-'0');
			v = (s[3]-'0') * 10 + (s[4]-'0');
			if(!seen.count({u,v})){
				in[v]++;
				g[u].push_back(v);
				cout << u << " ->  " << v << endl;
				seen.insert({u,v});
			}
		}
		else{
			a.push_back({0});
			for(int i = 0; i < s.size(); i++){
				if(s[i] == ',') a.back().push_back(0);
				else a.back().back() = a.back().back() * 10 + (s[i]-'0'); 
			}
		}
	}

	int ans = 0;

	int cnt = 0;

	for(auto v : a){

		vector<int> curin = in;

		set<int> has;
		for(int i : v) has.insert(i);

		queue<int> q;

		for(int i = 1; i < 100; i++) order[i] = 101;

		for(int i = 1; i < 100; i++){
			if(has.count(i) == 0){
				for(int j : g[i]){
					curin[j]--;
				}
			}
		}
		for(int j : v) if(curin[j] == 0 and has.count(j)) q.push(j), order[j] = 0;

		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int j : g[u]){
				curin[j]--;
				if(curin[j] == 0 and has.count(j)){
					order[j] = order[u]+1;
					q.push(j);
				}
			}
		}

		vector<int> b = v;
		sort(b.begin(), b.end(), [&](int u, int v) { return order[u] < order[v]; });

		for(int k : v) cout << order[k] << " ";
		cout << endl;

		for(int k : v) cout << k << " ";
		cout << endl;

		for(int k : b) cout << k << " ";
		cout << endl;
		cout << "--" << endl;

		if(v != b){
			ans += b[b.size()/2];
			cnt++;
		}
	}

	cout << cnt << " " << a.size() << endl;

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
    return 0;
}