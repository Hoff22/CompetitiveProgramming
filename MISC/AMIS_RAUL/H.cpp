#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define MOD 1000000009
typedef long long ll;
typedef unsigned long long ull;

int n;
set<int> pr;

long long DP[10004][10][10];

// xxxxxl1l2i

long long dp(int i, int l1, int l2){
    if(i == n) return 1;

    if(DP[i][l1][l2] != -1) return DP[i][l1][l2];

    long long ans = 0;

    for(int d = (i == 0); d <= 9 ; d++){
        if(i < 2 or pr.count(l1*100 + l2*10 + d)){
            ans += dp(i+1, l2, d);
            ans %= MOD;
        }
    }

    return DP[i][l1][l2] = ans % MOD;
}


void solve() {
    cin >> n;
    memset(DP, -1, sizeof(DP));
    cout << dp(0, 0, 0) % MOD << endl;
}

/*

x x x x x x x
0 1 2 3 4 5 6

1 2 3 
4 5 6
7 8 9

*/ 


int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /*

    3d : 999 - 10 => 989 -> 10^3 - (10^2 + 1);

    */

    for(int i = 100; i <= 999; i++){
        int p = 1;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                p = 0;
                break;
            }
        }
        if(p) pr.insert(i);
    }
    // xxx
    
    solve();

    return 0;
}