#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;

int j[32][N+1];

void solve(){
	int n, q;
	cin >> n >> q;

	vector<int> t(n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> t[i];
	}

	for(int i = 1; i <= n; i++){
		j[0][i] = t[i];
	}

	for(int p = 1; p <= 31; p++){
		for(int i = 1; i <= n; i++){
			j[p][i] = j[p-1][j[p-1][i]];
		}
	}

	while(q--){
		int i,k;
		cin >> i >> k;
		int p = 0;
		while(k){
			if(k&1){
				i = j[p][i];				
			}
			p++;
			k>>=1;
		}
		cout << i << endl;
	}
}
 
int main(){
 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1;
 
	while(t--){
		solve();
	}
 
	return 0;
}