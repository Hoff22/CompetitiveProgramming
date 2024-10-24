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

char a[N+1];

void solve(){
	int k;
	k = 2;
	string s;
	cin >> s;
	vector<int> ans(s.size()+1, 0);
	map<char,int> m;

	for(int i = 0; i < s.size(); i++) a[i+1] = s[i];

	vector<pair<char,int>> b;

	int cnt = 0;
	for(int i = 1; i <= s.size(); i++){
		if(m[a[i]] < k){
			cnt++;
			b.push_back({a[i], i});
		}
		m[a[i]]++;
	}

	sort(b.begin(), b.end());

	int c = 0;
	for(int i = 0; i < (cnt/k)*k; i++){
		ans[b[i].se] = c+1;
		c = (c+1)%k;
	}

	int res = 0;
	for(int i = 1; i <= s.size(); i++){
		if(ans[i] == 1) res++;
	}

	cout << res << endl;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}