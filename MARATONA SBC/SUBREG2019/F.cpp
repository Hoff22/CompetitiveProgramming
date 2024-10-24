#include <bits/stdc++.h>

#define N 1000
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

int n;
int jp[N+1];
vector<tuple<int,int,int,int>> s;

int DP[N+1][3000];

int dp(int i, int m){
    if(i == s.size()){
        if(m == (1<<n)-1) return 0;
        return -INF;
    }

    if(DP[i][m] != -1) return DP[i][m];

    int x, p;
    tie(ignore,ignore,x,p) = s[i];

    return DP[i][m] = max(dp(i+1,m), dp(jp[i], m|(1<<p)) + x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(DP, -1, sizeof(DP));

    cin >> n;

    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            int l,r,x;
            cin >> l >> r >> x;
            s.push_back({l,r,x,i});
        }
    }

    sort(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++) jp[i] = s.size();

    for(int i = 0; i < s.size(); i++){
        for(int j = i+1; j < s.size(); j++){
            int ra, lb;
            tie(ignore, ra, ignore, ignore) = s[i];
            tie(lb, ignore, ignore, ignore) = s[j];
            if(ra <= lb){
                jp[i] = j;
                break;
            }
        }
    }

    if(dp(0,0) <= 0) cout << -1 << endl;
    else cout << dp(0,0) << endl;

    return 0;
}