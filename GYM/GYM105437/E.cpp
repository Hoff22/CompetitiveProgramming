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
	int t;
	cin >> t;
	vector<int> n(t);
	vector<int> k(t);
	for(int i = 0; i < t; i++){
		cin >> n[i];
	}
	for(int i = 0; i < t; i++){
		cin >> k[i];
	}

	vector<ll> p2(100000+1);
	p2[0] = 1;
	for(int i = 1; i <= 100000; i++){
		p2[i] = (p2[i-1] * 2) % MOD;
	}

	for(int i = 0; i < t; i++){
		if(n[i] == k[i]) cout << (p2[n[i]]-1) % MOD << endl;
		else cout << p2[k[i]] << endl;
	}
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