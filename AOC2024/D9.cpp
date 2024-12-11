// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
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

void solve(){
	string s;
	cin >> s;

	int n = s.size();

	vector<int> res;
	set<pair<int,int>> fr;
	int id = 0;
	for(int i = 0; i < n; i++){
		if(i%2){
			fr.insert({(int)res.size(), (s[i]-'0')});
			for(int k = 0; k < (s[i]-'0'); k++) res.push_back(-1);
		}
		else{
			for(int k = 0; k < (s[i]-'0'); k++) res.push_back(id);
			id++;
		}
	}

	// for(auto [p,cap] : fr){
	// 	cout << "("<<p<<","<<cap<<")" << endl;
	// }

	// for(int i : res) (i == -1) ? cout << '.' : cout << i;
	// cout << endl;


	int sz = (res.back() != -1);
	for(int i = res.size()-2; i >= 0; i--){
		if(sz and res[i] != res[i+1]){

			int p = 0x3f3f3f3f, cap = 0;

			for(auto j : fr){
				tie(p,cap) = j;
				if(p >= i or cap >= sz) break;
			}

			if(cap >= sz and p < i){
				fr.erase({p,cap});
				if(cap > sz) fr.insert({p+sz,cap-sz});

				int idd = res[i+1];
				while(sz--){
					res[p+sz] = idd;
					res[i+sz+1] = -1; 
				}
			}

			sz = 0;

			// for(int k : res) (k == -1) ? cout << '.' : cout << k;
			// cout << endl;
			// cout << endl;
		}
		if(res[i] == -1) sz = 0;
		else sz++;
	}

	ull ans = 0;

	for(ull i = 0; i < res.size(); i++){
		if(res[i] == -1) continue;
		ans += (i * res[i]);
	}

	cout << ans << endl;

	// for(int i : res) (i == -1) ? cout << '.' : cout << i;
	// cout << endl;
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