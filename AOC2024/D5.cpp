// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>

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
	while(cin >> s){
		if(s[2] == '|'){
			int u, v;
			u = (s[0]-'0') * 10 + (s[1]-'0');
			v = (s[3]-'0') * 10 + (s[4]-'0');
			g[u].push_back(v);
			in[v]++;
		}
		else{
			a.push_back({0});
			for(int i = 0; i < s.size(); i++){
				if(s[i] == ',') a.back().push_back(0);
				else a.back().back() = a.back().back() * 10 + (s[i]-'0'); 
			}
		}
	}

	queue<int> q;

	for(int i = 1; i < 100; i++){
		if(!in[i]) q.push(i), order[i] = 0;
	}

	while(q.empty()){
		
	}
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