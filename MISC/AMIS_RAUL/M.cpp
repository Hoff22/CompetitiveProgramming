#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

long double l2[100];

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        // q is quotient
        ll q = A / M;
        ll t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();


    vector<ll> cnt(100,0);

    for(int i = 0; i < n; i+=2){
        cnt[((s[i] - '0') * 10 + (s[i+1] - '0'))]++;
    }

    vector<pair<long double, ll>> da = {make_pair(0.0, 1)}, db = {make_pair(0.0, 1)};

    for(int p = 1; p < 100; p++){
        if(!cnt[p]) continue;
        if(da.size() < 1e5){
            for(int i = da.size()-1; i >= 0; i--){
                ll cur = da[i].second;

                for(int k = 1; k <= cnt[p]; k++){
                    cur = (cur * p) % MOD;
                    da.push_back({da[i].first + l2[p] * k , cur});
                }
            } 
        }
        else{
            for(int i = db.size()-1; i >= 0; i--){
                ll cur = db[i].second;

                for(int k = 1; k <= cnt[p]; k++){
                    cur = (cur * p) % MOD;
                    db.push_back({db[i].first + l2[p] * k , cur});
                }
            } 
        }
        // cout << p << ": " << endl;
        // cout << "  > ";
        // for(auto [lg, d1] : da) cout << d1 << " ";
        // cout << endl;
        // cout << "  > ";
        // for(auto [lg, d1] : db) cout << d1 << " ";
        // cout << endl;
    }

    long double lsq = 0.0;
    ll k = 1, d = 1;

    for(int i = 2; i < 100; i++){
        if(!cnt[i]) continue;
        lsq += l2[i] * cnt[i];
        while(cnt[i]--){
            k = (k * i) % MOD;  
        }
    } 
    lsq /= 2;

    sort(da.begin(), da.end());
    sort(db.begin(), db.end());

    // for(auto [lg, d1] : da) cout << lg << "," << d1 << endl;
    // cout << endl;
    // for(auto [lg, d1] : db) cout << d1 << " ";
    // cout << endl;

    // return;

    long double ans = 0.0;

    // cout << lsq << endl;

    for(auto [lg, d1] : da){
        // cout << lg << ", " << d1 << " - ";
        auto i = upper_bound(db.begin(), db.end(), make_pair(lsq - lg + 0.0000001,1000000007ll));
        if(i == db.begin()){
            // cout << endl;
            break;
        }
        i--;
        // cout << i->first << ", " << i->second << endl;
        if(lg + i->first > ans){
            ans = lg + i->first;
            d = (i->second * d1) % MOD;
        }
    }

    // cout << d << endl;

    cout << (d + (k * modInverse(d,MOD)) % MOD) % MOD << endl;
}

/*
    max targ 1154.98

    X
    
    log(sqrt(X)) == 1/2 * log(X)
    
    X == abcd

    log(X) == log(a) + log(b) + log(c) + log(d)

    log(sqrt(X)) = 1/2 * (log(a) + log(b) + log(c) + log(d))

*/ 


int main() {

    for(int i = 1; i < 100; i++) l2[i] = log10l(i);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}