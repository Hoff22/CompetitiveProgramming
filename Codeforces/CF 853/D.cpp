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

string shift(const string& s0, int k){
	if(k == 0) return s0;

	string s = s0;

	if(k < 0){
		k *= -1;
		reverse(s.begin(), s.end());
		s = s.substr(0, s.size()-k);
		reverse(s.begin(), s.end());
		for(int i = 0; i < k; i++) s += "0";
	}
	else{
		s = s.substr(0, s.size()-k);
		reverse(s.begin(), s.end());
		for(int i = 0; i < k; i++) s += "0";
		reverse(s.begin(), s.end());
	}

	for(int i = 0 ; i < s.size(); i++){
		if((s0[i] == '1') and (s[i] == '1')) s[i] = '0';
		else if((s0[i] == '1') or (s[i] == '1')) s[i] = '1';
	}

	return s;
}

void solve(){
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	if(a == b){
		cout << 0 << endl;
		return;
	}

	vector<int> ans;

	for(int i = -n; i <= n; i++){
		string ns = shift(a, i);

		int good = 1;
		int j;
		for(j = 0; j < n; j++){
			if(ns[j] != b[j]){
				good = 0;
				break;
			}
			if(b[j] == '1') break;
		}
		if(!good) continue;

		ans.push_back(i);

		for(int r = 0; r+j < n; r++){
			if(ns[r+j] != b[r+j]){
				ans.push_back(r);
				ns = shift(ns, r);
			}
		}

		break;
	}

	if(ans.size()){
		int i = 0;
		int r = ans.size();
		if (ans.front() == 0) {r--; i++;}

		cout << r << endl;
		for(; i < ans.size(); i++) cout << -ans[i] << " ";
		cout << endl;

		return;
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for(int i = -n; i <= n; i++){
		string ns = shift(a, i);

		int good = 1;
		int j;
		for(j = 0; j < n; j++){
			if(ns[j] != b[j]){
				good = 0;
				break;
			}
			if(b[j] == '1') break;
		}
		if(!good) continue;

		ans.push_back(i);


		for(int r = 1; r+j < n; r++){
			if(ns[r+j] != b[r+j]){
				ans.push_back(r);
				ns = shift(ns, r);
			}
		}

		break;
	}

	if(ans.size()){
		int i = 0;
		int r = ans.size();
		if (ans.front() == 0) {r--; i++;}

		cout << r << endl;
		for(; i < ans.size(); i++) cout << ans[i] << " ";
		cout << endl;

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