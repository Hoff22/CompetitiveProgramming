#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n, a, q;
	cin >> n >> a >> q;
	int c = n-a;
	int cur = a;
	int def = (cur == n);
	for(int i = 0; i < q; i++){
		char k; cin >> k;
		if(k == '+'){
			c--;
			cur++;
		}
		else{
			cur--;
		}

		if(cur == n) def = 1;
	}

	if(def){
		cout << "YES" << endl;
	}
	else{
		if(c <= 0) cout << "MAYBE" << endl;
		else cout << "NO" << endl;
	}
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