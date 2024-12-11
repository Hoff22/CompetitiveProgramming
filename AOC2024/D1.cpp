// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll cnt(double lg10, int k){
	if(!k) return 1;

	if(floor(lg10) % 2 == 0){
		return cnt(lg10/2, k-1) + cnt(lg10/2, k-1);
	}
	return cnt(lg10 * 3.30621051, k-1);
}

void solve(){
	ll n = 8;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		ans += cnt(log10l(x), 25);		
	}
	cout << ans << endl;
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