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

bool possible(vector<int> &items, int k, int test) {
    int boxes = 1;

    int curr = 0;

    for(int i = 1; i < (int)items.size(); i++) {
        if(items[i] > test) return false;
        if(curr + items[i] > test) {
            if(boxes >= k) return false;
            curr = items[i];
            boxes++;
        } else {
            curr += items[i];
        }
    }

    return true;
}

void solve() {
    int n, k;

    cin >> n >> k;

    vector<int> items(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    int ans = INT_MAX;

    int l = 1, r = 1e9+100;

    while(l <= r) {
        int mid = l + (r-l)/2;

        if(possible(items, k, mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << "\n";
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}