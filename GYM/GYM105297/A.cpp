#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
typedef long long ll;

#define eps 0.00000001

void solve(){
    int n; cin >> n;
    vector<tuple<int,int,int, int>> v;
    for(int i = 1; i <= n; i++){
    	int t, m, c;
    	cin >> t >> m >> c;
    	v.push_back({t,m,c,i});
    }

    sort(v.begin(), v.end());
    vector<int> ans;

    deque<tuple<int,int,int, int>> q;

    int tin, tout;
    tin = tout = 0;

    for(auto [t,m,c,i] : v){
    	while(q.size() and t > tout){
    		q.pop_front();
    		if(q.empty()) continue;
    		tin = tout + 1;
    		tout = tin + get<1>(q.front()) - 1;
    	}

		if(q.empty()){
			tin = t;
			tout = t + m - 1;
    		q.push_back({t,m,c,i});
		}
    	else if(c){
			ans.push_back(get<3>(q.front()));
			q.pop_front();
			q.push_front({t,m,c,i});
			tin = t;
			tout = t + m - 1;
    	}
    	else{
    		q.push_back({t,m,c,i});
    	}
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; n =1;
    
    for(int i = 0; i < n; ++i){
        solve();
    }
    
    return 0;
}