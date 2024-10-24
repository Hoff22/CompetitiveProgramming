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
	int n;
	cin >> n;

	set<int> s;
	for(int i = 0; i < n; i++){
		int x;cin >> x;
		s.insert(x);
	}

	int mex = 0;
	for(int i : s){
		if(i == mex) mex++;
		else break;
	}

	int l = -1;
	int t = 1;
	while(true){

		if(t%2){
			if(l == -1) cout << mex << endl;
			else cout << l << endl;
		}
		else{
			int y; cin >> y;
			assert(y != -2);
			if(y == -1) return;
			l = y;
		}

		t++;
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