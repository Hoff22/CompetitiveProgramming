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

	int good = 1;
	int a = (s[0] == 'a');
	int b = (s[0] == 'b');
	for(int i = 1; i < s.size(); i++){
		if(s[i] == 'a') a++;
		if(s[i] == 'b') b++;
		if(s[i] != s[i-1]){
			if((a == 1 and s[i] == 'b') or (b == 1 and s[i] == 'a')) good = 0;
			a = (s[i] == 'a');
			b = (s[i] == 'b');
		}
	}
	if(a == 1 or b == 1) good = 0;

	if(good) cout << "YES\n";
	else cout << "NO\n";
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