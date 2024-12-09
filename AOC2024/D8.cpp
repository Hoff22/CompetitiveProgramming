// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
#include<set>
#include<map>

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

#define LLMAX 9223372036854775807

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define N 10000

// --------- end of template ---------

vector<string> a;
map<char, vector<pair<int,int>>> b;

void solve(){

    string s;
    while(cin >> s){
        a.push_back(s);
    }

    int n = a.size(), m = a[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != '.') b[a[i][j]].push_back({i,j});
        }
    }

    auto isInside = [&](pair<int,int> p) {return p.fi >= 0 and p.fi < n and p.se >= 0 and p.se < m;};

    set<pair<int,int>> ans;

    for(auto [c, v] : b){
        for(auto [i,j] : v){
            for(auto [k,l] : v){
                if(i == k and j == l) continue;

                int iof = (k-i), jof = (l-j);

                pair<int,int> p = {i + iof, j + jof};
                while(isInside(p)){
                    ans.insert(p);
                    p.fi += iof;
                    p.se += jof;
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(!ans.count({i,j})) cout << a[i][j];
    //         else cout << '#';
    //     }
    //     cout << endl;
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