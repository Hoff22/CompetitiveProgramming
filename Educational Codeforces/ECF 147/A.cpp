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
	string s;
	cin >> s;

	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '?') cnt++;
	}

	if(s[0] == '0'){
		cout << 0 << endl;
		return;
	}

	long long ans = 1;
	if(s[0] == '?'){
		ans *= 9;
		for(int i = 0; i < cnt-1; i++){
			ans *= 10;
		}
	}
	else{
		for(int i = 0; i < cnt; i++){
			ans *= 10;
		}
	}
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