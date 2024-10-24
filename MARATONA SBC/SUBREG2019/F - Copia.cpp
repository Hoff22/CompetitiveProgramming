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

int dp(int i, int m){
    if(jp[i] == -1){
        if(m == (1<<n)-1) return 0;
        return -INF;
    }

    return max()
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(jp, -1, sizeof(jp));

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

    return 0;
}