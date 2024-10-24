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

int tr(vector<int>& ans, string& s){
	stack<int> b;
	stack<int> a;
	int n = s.size();

	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			if(b.empty()){
				a.push(i);
			}
			else{
				ans[i] = 2;
				ans[b.top()] = 2;
				b.pop();
			}
		}
		else{
			if(a.empty()){
				b.push(i);
			}
			else{
				ans[i] = 1;
				ans[a.top()] = 1;
				a.pop();
			}
		}
	}

	return (a.empty() and b.empty());
}

void solve(){
	int n;
	string s;
	cin >> n >> s;

	vector<int> ans(n, 0);

	if(tr(ans, s)){
		int mn = INF;
		int mx = 0;
		for(int i = 0; i < n; i++){
			mn = min(mn, ans[i]);
			mx = max(mx, ans[i]);
		}

		if(mn == mx){
			cout << 1 << endl;
			for(int i = 0; i < n; i++) cout << 1 << " ";
			cout << endl;
		}
		else{
			cout << 2 << endl;
			for(int i = 0; i < n; i++) cout << ans[i] << " ";
			cout << endl;
		}

		return;
	}

	reverse(s.begin(), s.end());

	if(tr(ans, s)){
		int mn = INF;
		int mx = 0;
		for(int i = 0; i < n; i++){
			mn = min(mn, ans[i]);
			mx = max(mx, ans[i]);
		}

		if(mn == mx){
			cout << 1 << endl;
			for(int i = 0; i < n; i++) cout << 1 << " ";
			cout << endl;
		}
		else{
			cout << 2 << endl;
			for(int i = 0; i < n; i++) cout << ans[i] << " ";
			cout << endl;
		}

		return;
	}

	cout << -1 << endl;
	
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