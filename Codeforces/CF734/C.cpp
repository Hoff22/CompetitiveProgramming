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

int n;
char c;

int val(const string& s){
	int r = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == c) r++;
		else r--; 
	}
	return r;
}

bool comp(const string& a, const string& b){
	return (val(a) > val(b));
}

void solve(){
	cin >> n;

	vector<string> v;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}

	int ans = 0;
	for(c = 'a'; c <= 'e'; c++){
		sort(v.begin(), v.end(), comp);
		int cur = 0;
		int i;
		for(i = 0; i < n; i++){
			cur += val(v[i]);
			if(cur <= 0) break;
		}
		ans = max(ans, i);
	}

	cout << ans << endl;

}

int main(){
	
	int t;
	cin >> t;	
	while(t--){
		solve();
	}
    return 0;

}