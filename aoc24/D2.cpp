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

void solve(){
	ifstream file("A1.in");
	if(!file){
		cerr << "can't open file" << endl; 
		exit(1);
	}

	int ans = 0;

	while(true){
		string s;
		getline(file, s);
		if(s.empty()) break;
		vector<int> v = {0};
		for(char c : s){
			if(c == ' ') v.push_back(0);
			else{
				v[v.size()-1] *= 10;
				v[v.size()-1] += (int)(c - '0');
			}
		}
		if(v.size() == 1) continue;

		int good = 0;
		for(int j = 0; j < v.size(); j++){
			int mx = 0;
			int mn = 0x3f3f3f3f;
			int z = 0;
			for(int i = 1; i < v.size(); i++){

				if(j == i or (j == 0 and i == 1)) continue;
				int dif = v[i]-v[i-1];
				if(j == i-1) dif = v[i]-v[i-2];

				mx = max(mx, dif);
				mn = min(mn, dif);
				z |= dif == 0;
			}

			if((mx > 0 and mn < 0) or z or mn < -3 or mx > 3) continue;

			good = 1;
		}

		ans += good;
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