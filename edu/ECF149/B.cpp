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
	string s;
	cin >> n >> s;

	int ans = 0;
	int cur = 2;

	for(int i = 1; i < n; i++){
		if(s[i] == s[i-1]) cur++;
		else{
			ans = max(ans, cur);
			cur = 2;
		}
	}

	ans = max(ans, cur);

	cout << ans << endl;
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