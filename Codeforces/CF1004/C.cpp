#include <bits/stdc++.h>

#define N 300
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;

using namespace std;

ll p10[10];

inline ll dig(ll n, ll i){
    return (n/p10[i])%10;
}

void solve(){
    ll n;
    cin >> n;

    int ans = 0x3f3f3f3f;

    ll nine = 0;
    for(ll i = 0; i < 10; i++){
        for(int k = 0; k <= 10; k++){
            int d = dig(n + nine * k, i);
            if(d == 7 or (d + 9*k) % 10 == 7) ans = min(ans, k);
        }   
        nine = (nine * 10) + 9;
    }

    cout << ans << endl;
}

int main(){
    p10[0] = 1;
    for(ll i = 1; i < 10; i++) p10[i] = p10[i-1] * 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}