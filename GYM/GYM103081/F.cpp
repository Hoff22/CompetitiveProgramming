#include <bits/stdc++.h>

#define N 2021
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

typedef long long ll;

int r,m;
int mn;
ll choose[N+1][N+1];
void pascal(){
	for(int i = 0; i <= N; i++) choose[i][0] = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % m;
		}
	}
}

ll T[N+1];
ll DP[N+1];

ll t(int n){
	if(n <= 1) return 1;

	if(T[n] != -1) return T[n];

	ll res = 0;
	for(int i = 0; i <= n-2; i++){
		res += (t(i+1) * t(n-2-i) % m) * choose[n-2][i] % m;
		res %= m;
	}

	return T[n] = res;
}

ll dp(int n){
	if(n == mn) return t(n);

	if(DP[n] != -1) return DP[n];

	ll res = t(n);
	for(int k = 1; k <= min(r-1, n-mn); k++){
		res -= ((dp(n-k) * t(k+1) % m) * choose[n-mn][k] % m);
		res %= m;
	}

	return DP[n] = res;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> r >> n >> m;
    pascal();

    memset(T, -1, sizeof(T));
    memset(DP, -1, sizeof(DP));

    mn = n-r+1;
	cout << (dp(n) + m) % m << endl;
	
    return 0;

}