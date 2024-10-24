#include <bits/stdc++.h>

#define N 1000000
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

int b[N+1];

void solve(){
	int n;
	string s;

	cin >> n >> s;

	for(int i = 1; i <= n; i++){
		if(s[i-1] == '0'){
			b[i] = 0;
		}
	}
/*

	1 2 3 4
	2 3 5 7

*/
	long long ans = 0;
	for(int i = 1; i <= n; i++){

		if(s[i-1] == '1') continue;
		if(b[i] == 0) ans += i;

		long long j = i + i;
		while(j <= n and s[j-1] == '0'){

			if(b[j] == 0){
				b[j] = 1;
				ans += i;
			}

			j+=i;
		} 
		//cout << i<< ": "<< ans << endl;
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