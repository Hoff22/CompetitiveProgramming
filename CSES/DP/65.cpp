#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 500;
constexpr int M = (500*501);
 
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
 
int n, m;
int DP[N+1][M+1];
 
int dp(int i, int s){
	if(i>n){
		return (2*s == m);
	}
 
	if(DP[i][s] != -1) return DP[i][s];
 
	return DP[i][s] = (dp(i+1,s) + dp(i+1, s+i)) % MOD;
}
 
void solve(){
	memset(DP,-1,sizeof(DP));
 
	cin >> n;
	m = (n*n+n)/2;
 
	cout << (dp(1,0) * modular_inverse(2, MOD)) % MOD << endl;
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