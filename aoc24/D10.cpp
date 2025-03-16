// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int n = 0, m = 0;
vector<string> a;
queue<pair<int,int>> q;
vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool inside(int i, int j){
	return (i >= 0 and j >= 0 and i < n and j < m);
}
bool inside(pair<int,int> u){
	return (u.fi >= 0 and u.se >= 0 and u.fi < n and u.se < m);
}

void solve(){
	string s;
	while(cin >> s){
		a.push_back(s);
	}

	n = a.size(), m = a[0].size();

	vector<vector<int>> qnt(n, vector<int>(m,0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '0') q.push({i,j}), qnt[i][j] = 1;
		}
	}

	while(q.size()){
		int i,j;
		tie(i,j) = q.front();
		q.pop();

		for(auto d : dir){
			int ni = i + d.fi;
			int nj = j + d.se;

			if(inside(ni,nj)){
				if(a[ni][nj] - a[i][j] != 1) continue;
				if(!qnt[ni][nj]) q.push({ni,nj});
				qnt[ni][nj] += qnt[i][j];
			}
		}
	}

	ull ans = 0;
	set<pair<int,int>> seen;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '9'){
				ans += qnt[i][j];
				cout << qnt[i][j] << " ";
			}
			else cout << ". ";
		}
		cout << endl;
	}

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