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
	int good = 0;
	int cnt = 0;
	int l = -1;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == l) cnt++;
		else cnt = 1;

		if(cnt == 3) good = 1;
		l = x;
	}

	cout << (good?"Yes" : "No") << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
    return 0;
}