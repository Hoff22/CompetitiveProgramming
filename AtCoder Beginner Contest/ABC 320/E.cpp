#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;

    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);

    vector<ll> ans(n+1, 0);

    vector<ll> ts;
    vector<pair<ll,ll>> qs;
    vector<vector<int>> pin;
    for(int i = 0; i < m; i++){
        ll t, w, si;
        cin >> t >> w >> si;
        ts.push_back(t);
        qs.push_back({w,si});
        pin.push_back(vector<int>());
    }

    for(int i = 0; i < m; i++){
        ll t, w, si;
        t = ts[i];
        tie(w, si) = qs[i];

        for(int j : pin[i]) s.insert(j);
        if(s.size()){
            ans[*s.begin()] += w;
            auto j = lower_bound(ts.begin(), ts.end(), t+si);
            if(j != ts.end()){
                int idxj = (int)(j-ts.begin());
                pin[idxj].push_back(*s.begin());
            }
            s.erase(*s.begin());
        } 
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
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