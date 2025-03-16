// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool isXMAS(vector<char> &s){
	return (s[0] == 'X' and s[1] == 'M' and s[2] == 'A' and s[3] == 'S');
}

void solve1(){
	int n = 8, m = 4;
	vector<string> a(4, "####");
	string cur;
	while(cin >> cur){
		n++;
		cur = "####" + cur + "####";
		m = max(m, (int)cur.size());
		a.push_back(cur);
	}

	for(int i = 0; i < 4; i++) a.push_back("####");

	for(int i = 0; i < n; i++){
		while(a[i].size() < m) a[i].push_back('#');
	}

	int ans = 0;

	// vector<string> b = a;

	for(int i = 4; i < n-4; i++){
		for(int j = 4; j < m-4; j++){
			cout << a[i][j];
			static vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
			for(auto d : dir){
				vector<char> t;
				for(int k = 0; k < 4; k++){
					t.push_back(a[i+d[0]*k][j+d[1]*k]);
				}
				// if(isXMAS(t)){
				// 	for(int k = 0; k < 4; k++){
				// 	 	b[i+d[0]*k][j+d[1]*k] = 'o';
				// 	}	
				// }
				ans += isXMAS(t);
			}
		}
		cout << endl;
	}

	// for(int i = 0; i < n; i++){
	// 	cout << b[i] << endl;
 	// }

	cout << ans << endl;
}

void solve(){
	int n = 8, m = 4;
	vector<string> a(4, "####");
	string cur;
	while(cin >> cur){
		n++;
		cur = "####" + cur + "####";
		m = max(m, (int)cur.size());
		a.push_back(cur);
	}

	for(int i = 0; i < 4; i++) a.push_back("####");

	for(int i = 0; i < n; i++){
		while(a[i].size() < m) a[i].push_back('#');
	}

	int ans = 0;

	// vector<string> b = a;

	for(int i = 4; i < n-4; i++){
		for(int j = 4; j < m-4; j++){
			if(a[i][j] == 'A'){
				if(a[i-1][j-1] == 'M' and a[i+1][j+1] == 'S'){
					ans += (a[i+1][j-1] == 'S' and a[i-1][j+1] == 'M') or (a[i+1][j-1] == 'M' and a[i-1][j+1] == 'S');
				}
				if(a[i-1][j-1] == 'S' and a[i+1][j+1] == 'M'){
					ans += (a[i+1][j-1] == 'S' and a[i-1][j+1] == 'M') or (a[i+1][j-1] == 'M' and a[i-1][j+1] == 'S');
				}
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << b[i] << endl;
 	// }

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