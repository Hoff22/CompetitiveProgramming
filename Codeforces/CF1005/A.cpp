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
	string s;
	cin >> s;

	reverse(s.begin(), s.end());
	while(s.size() and s.back() == '0') s.pop_back();
	s.push_back('0');
	reverse(s.begin(), s.end());

	int cnt = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] != s[i-1]) cnt++;
	}
	cout << cnt << endl;
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