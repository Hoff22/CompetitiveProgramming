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

	long long ans = 0;
	vector<string> s(n); 
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	vector<map<int,int>> l(5+1, map<int,int>());
	for(int i = 0; i < n; i++){
		// cout << i << "::::" << endl;
		int tot = 0;
		for(int j = 0; j < s[i].size(); j++) tot += (s[i][j]-'0');
		int cur = 0;

		for(int j = 0; j < s[i].size(); j++){
			cur += (s[i][j]-'0');
			int ls = j+1;
			if(2*ls <= s[i].size()) continue;
			int rs = s[i].size()-ls;
			ans += l[ls-rs][cur-(tot-cur)];
			// cout << j << ": " << ls << " " << rs << " " << cur << " " << l[ls-rs][cur-(tot-cur)] << endl;
		}

		reverse(s[i].begin(), s[i].end());
		l[s[i].size()][tot]++;
		// cout << "--------" << endl;

		cur = 0;
		for(int j = 0; j < s[i].size(); j++){
			cur += (s[i][j]-'0');
			int ls = j+1;
			if(2*ls <= s[i].size()) continue;
			int rs = s[i].size()-ls;
			ans += l[ls-rs][cur-(tot-cur)];
			// cout << j << ": " << ls << " " << rs << " " << cur << " " << l[ls-rs][cur-(tot-cur)] << endl;
		}

		// cout << "ans: " << ans << " " << endl;
	}

	reverse(s.begin(), s.end());
	l.assign(6, map<int,int>());
	for(int i = 0; i < n; i++){
		// cout << i << "::::" << endl;
		int tot = 0;
		for(int j = 0; j < s[i].size(); j++) tot += (s[i][j]-'0');
		int cur = 0;

		for(int j = 0; j < s[i].size()-1; j++){
			cur += (s[i][j]-'0');
			int ls = j+1;
			if(2*ls <= s[i].size()) continue;
			int rs = s[i].size()-ls;
			ans += l[ls-rs][cur-(tot-cur)];
			// cout << j << ": " << ls << " " << rs << " " << cur << " " << l[ls-rs][cur-(tot-cur)] << endl;
		}

		reverse(s[i].begin(), s[i].end());
		// cout << "--------" << endl;

		cur = 0;
		for(int j = 0; j < s[i].size()-1; j++){
			cur += (s[i][j]-'0');
			int ls = j+1;
			if(2*ls <= s[i].size()) continue;
			int rs = s[i].size()-ls;
			ans += l[ls-rs][cur-(tot-cur)];
			// cout << j << ": " << ls << " " << rs << " " << cur << " " << l[ls-rs][cur-(tot-cur)] << endl;
		}

		l[s[i].size()][tot]++;
		// cout << "ans: " << ans << " " << endl;
	}

	// cout << endl;

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}