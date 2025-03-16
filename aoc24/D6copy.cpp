// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<set>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

map<char, tuple<int,int,char>> arrow = {{'<', {0,-1,'^'}}, {'^', {-1,0,'>'}}, {'>', {0,1,'v'}}, {'v', {1,0,'<'}}};

void solve(){
	vector<string> a;
	string s;

	while(cin >> s){
		a.push_back(s);
	}
	int n = a.size();
	int m = a[0].size();
	
	cout << n << " " << m << " - -- - - " << endl;

	vector<vector<set<char>>> used(n, vector<set<char>>(m,set<char>()));

	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(arrow.count(a[i][j])){
				break;
			}
		}
		if(j < m) break;
	}

	auto isInside = [&](int y, int x){
		return (y >= 0 and y < n and x >= 0 and x < m);
	};

	function<int(int,int,char,set<tuple<int,int,char>>&)> find = [&](int y, int x, char cur, set<tuple<int,int,char>>& seen){

		// cout << "> " <<  y << " " << x << endl;

		if(seen.count({y,x,cur})) return 1;
		seen.insert({y,x,cur});

		int ni = y + get<0>(arrow[cur]);
		int nj = x + get<1>(arrow[cur]);

		if(!isInside(ni,nj)) return 0;

		int k = 0;
		while(a[ni][nj] == '#'){
			// cout << "> > " << ni << " " << nj << endl;
			if(!isInside(ni,nj)) return 0;
			cur = get<2>(arrow[cur]);
			ni = y + get<0>(arrow[cur]);
			nj = x + get<1>(arrow[cur]);
			k++;
			if(k > 6) return 1;
		}

		return find(ni,nj,cur,seen);
	};

	set<pair<int,int>> ans;

	do{
		// {
		// 	cout << i << " " << j << ": " << endl;
		// 	for(int y = 0; y < n; y++){
		// 		for(int x = 0; x < m; x++){
		// 			cout << a[y][x];
		// 		}
		// 		cout << endl;
		// 	}
		// 	cout << endl;
		// }

		// cout << used.size() << endl << used[i].size() << endl << used[i][j].size() << endl;
		if(used[i][j].count(a[i][j])) break;
		used[i][j].insert(a[i][j]);
		int nx, di, dj;
		tie(di, dj, nx) = arrow[a[i][j]];
		int ni = i + di;
		int nj = j + dj;


		if(!isInside(ni,nj)) continue;
		
		if(a[ni][nj] != '#'){
			char tmp = a[ni][nj];
			a[ni][nj] = '#';

			// cout << "pintei " << ni << " " << nj << endl;

			set<tuple<int,int,char>> seen;
			if(find(i,j,a[i][j],seen)){
				// cout << "CICLE " <<  ni << " " << nj << " " << (char)nx << endl;
				ans.insert({ni,nj});
			}

			a[ni][nj] = tmp;
		}

		
		if(a[ni][nj] == '#'){
			a[i][j] = nx;
			continue;
		}
		a[ni][nj] = a[i][j];
		i = ni;
		j = nj;
	}while(isInside(i, j));


	// cout  << "end!! " << i << " " << j << ": " << endl;

	// for(auto [y,x] : ans){
	// 	a[y][x] = 'o';
	// }

	// {
	// 	for(int y = 0; y < n; y++){
	// 		for(int x = 0; x < m; x++){
	// 			cout << a[y][x];
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }

	cout << ans.size() << endl;
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