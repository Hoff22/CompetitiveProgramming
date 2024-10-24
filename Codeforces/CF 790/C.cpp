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

int diff(string a, string b){
	int dif = 0;
	for(int i = 0; i < a.size(); i++){
		dif += abs(a[i] - b[i]);
	}
	return dif;
}

void solve(){
	int n ,m;
	cin >> n >> m;

	int ans = INF;

	vector<string> v;
	for(int i = 0 ; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < i; j++){
			ans = min(ans, diff(s, v[j]));
		}
		v.push_back(s);	
	}

	cout << ans << endl;
}
// 
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