#include <bits/stdc++.h>
 
#define fi first
#define se second
#define MOD 1000000007
#define N 1000000
 
using namespace std;
 
typedef long long ll;
 
/* O(Log(min(a, b))) - Extended Euclidean Algorithm.
   Returns a solution to a * x + b * y = gcd(a, b).
   Returns |x| <= |a / gcd(a, b)|, |y| <= |b / gcd(a, b)| and gcd(a, b). */
tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    long long x, y, gcd;
 
    if (a == 0) {
        return {b, 0, 1};
    }
 
    tie(gcd, x, y) = extended_gcd(b % a, a);
 
    return {gcd, y - (b / a) * x, x};
}
 
/* O(Log(M)) - Returns the modular multiplicative inverse of a mod m, if it exists.
Returns x that satisfies a * x = 1 (mod m) if a and m are coprime. Returns 0 otherwise. */
long long modular_inverse(long long a, long long m) {
    long long gcd, x, y;
 
    tie(gcd, x, y) = extended_gcd((a % m + m) % m, m);
 
    if (gcd != 1) {
        return 0;
    }
 
    return (x % m + m) % m;
}
 
// O(log_2(N))
long long fast_pow(long long a, long long b, long long mod){
    long long res = 1;
    while(b){
        if(b&1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % MOD; 
}
 
void solve(){
    long long n;
    cin >> n;
 
    if(n == 1){
        cout << 2 << endl;
        return;
    }

    long long ans = 0;
    ans = (ans + fast_pow(2,(n*n),MOD)) % MOD;                                                 // 0
    ans = (ans + fast_pow(2,(n*n)/4 + (n%2),MOD)) % MOD;                                       // 90
    ans = (ans + (fast_pow(2,(n*n)/4 + (n%2),MOD) * fast_pow(2,(n*n)/4,MOD)) % MOD) % MOD;     // 180
    ans = (ans + fast_pow(2,(n*n)/4 + (n%2),MOD)) % MOD;                                       // 270
    
    cout << (ans * modular_inverse(4,MOD)) % MOD << endl;
}
 
//  24   -  12   +   4   - 1
// 4!/1! - 4!/2! + 4!/3! - 1
 
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}