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
long long a[N+1];
long long DP[N+1][2];
long long seen[N+1][2];

long long dp(int i, int of){
	if(i > n) return 0;

	if(seen[i][of]) return DP[i][of];
	seen[i][of] = 1;

	if((i+of)%2){
		return DP[i][of] = max({dp(i+1, of), dp(i+1, !of) + a[i], dp(i+1, of) + a[i]});
	}

	return DP[i][of] = max(dp(i+1, of), dp(i+1, !of));
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i <= n; i++){
		seen[i][0] = seen[i][1] = 0;
	}

	a[0] = 0;
	DP[1][0] =  0ll;
	DP[1][1] = a[1];

	for(int i = 2; i <= n; i++){
		if(i%2){
			DP[i][0] = max(DP[i-1][0],	DP[i-1][1] + a[i]);	// nessa
			DP[i][1] = max(DP[i-1][0],	DP[i-1][1] + a[i]);
		}
		else{
			DP[i][0] = max(DP[i-1][0], 	DP[i-1][1] + a[i]);
			DP[i][1] = max({DP[i-1][0],	DP[i-1][1], DP[i-1][1] + a[i]});	// nessa
		}
	}

	cout << max(DP[n][0], DP[n][1]) << endl;
}

/*
1 2 3 5 6 7 8
      4 5 6 7


1 ^ 2 ^ 5   = 6
001 010 101 = 110

111 100 011


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