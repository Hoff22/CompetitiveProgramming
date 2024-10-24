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
	string s;
	cin >> s;

	int f = 0;
	for(int i = 0; i < n/2; i++){
		if(f == 0 and s[i] != s[n-i-1]) f = 1;
		else if(f == 1 and s[i] == s[n-i-1]) f = 2;
		else if(f == 2 and s[i] != s[n-i-1]){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

}

/*

0111011

*/

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