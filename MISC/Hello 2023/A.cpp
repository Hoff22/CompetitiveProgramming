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

	for(int i = 0; i < n-1; i++){
		if(s[i] == 'R' and s[i+1] == 'L'){
			cout << 0 << endl;
			return;
		}
		if(s[i] == 'L' and s[i+1] == 'R'){
			cout << i+1 << endl;
			return;
		}
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