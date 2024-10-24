#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 1000;
constexpr int M = 1000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

typedef long long ll;

void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt = 0;
	int d = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(') d++;
		if(s[i] == ')') if(d) d--, cnt++;
	}	

	cout << cnt*2 << endl;
	
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