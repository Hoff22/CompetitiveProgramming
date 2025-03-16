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
	int q;
	cin >> q;

	stack<int> st;
	for(int i = 0; i <  q; i++){
		int op;
		cin >> op;
		if(op == 1){
			int x; cin >> x;
			st.push(x);
		}
		else{
			if(st.empty()) cout << 0 << endl;
			else cout << st.top() << endl;
			if(!st.empty()) st.pop();
		}
	}
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