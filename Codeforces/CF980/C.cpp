#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}

	sort(v.begin(), v.end(), [&](pair<int,int> i, pair<int,int>j) {
		return (i.fi+i.se) < (j.fi+j.se);
	});

	for(auto i : v) cout << i.fi << " " << i.se << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
    return 0;
}