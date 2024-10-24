#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

void solve(){
	map<char,long long> v;
	v['I'] = 1;
	v['V'] = 5;
	v['X'] = 10;
	v['L'] = 50;
	v['C'] = 100;
	v['D'] = 500;
	v['M'] = 1000;
	string s;
	cin >> s;

	int mx = 0;
	int ans = 0;
	for(int i = s.size()-1; i >= 0; i--){
		if(v[s[i]] < mx) ans -= v[s[i]];
		else{
			mx = v[s[i]];
			ans += v[s[i]];
		} 
	}

	cout << ans << endl;
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