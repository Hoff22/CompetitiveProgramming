#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 500;
constexpr int M = (500*501);
 
// O(N*log(N))
// returns the size of the lis
int lis(vector<int>& a){
    int n = a.size();
    vector<int> d(n+1, INF);
    d[0] = -INF;
 
    int ans = 0;
    for(int i = 0; i < n; i++){
        int j = (int)(lower_bound(d.begin(), d.end(), a[i]) - d.begin());
        if(j > n) continue;
        d[j] = min(a[i], d[j]);
        ans = max(ans, j);
    }
 
    return ans;
}
 
void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << lis(a) << endl;
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
