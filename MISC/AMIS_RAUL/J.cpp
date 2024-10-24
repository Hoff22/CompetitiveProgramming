#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define MOD 1000000009
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    vector<int> ele;
    ele = a;
    sort(ele.begin(),ele.end());
    ele.resize(unique(ele.begin(), ele.end()) - ele.begin());
    reverse(ele.begin(),ele.end());

    long long ans = 0;
    for(int e : ele){
        vector<int> l(a.size(), 0);
        for(int i = 1; i < a.size(); i++) l[i] += l[i-1] + (a[i-1] == e); 

        int up = 0;
        for(int i = a.size()-1; i >= 0; i--){
            if(a[i] != e) continue;
            if(i - l[i] > (a.size()-i-1) - up){
                ans += (a.size()-i-1) - up;
                up++;
            }
            else{
                ans += i - l[i];
            }
        }

        vector<int> b;
        for(int i : a) if(i != e) b.push_back(i);
        swap(a,b);
    }

    cout << ans << endl;
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
    
    solve();

    return 0;
}