#include <bits/stdc++.h>
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
using namespace std;
 
#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull; 

void solve() {
    int t = 1;

    cout << t << "\n";

    int n = 200000;
    for(int i = 1; i <= t; i++) {
        cout << n << "\n";
        for(int j     = 1; j <= n; j++) {
            cout << 735134400 << " \n"[j==n];
        } 
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
 
    return 0;
}