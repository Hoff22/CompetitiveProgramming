#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

#define endl '\n'

using namespace std;

vector<int> yv(35,0);
vector<int> xv(35,0);

long long DP[35][2][2][21];

long long dp(int i, int ey, int ex, int k){
	if(i < 0) return (k==0);
	if(k < 0) return 0;
	if(ex and xv[i] > 1) return 0;
	// if(ey and yv[i] < 1) return 0;

	if(DP[i][ey][ex][k] != -1) return DP[i][ey][ex][k];


	if(ex and xv[i]){
		// tenho que por 1
		return DP[i][ey][ex][k] = dp(i-1, ey & (yv[i] == 1), ex, k-1);
	}

	if(ey and !yv[i]){
		// tenho que botar 0
		return DP[i][ey][ex][k] = dp(i-1, ey, ex & (xv[i] == 0), k);
	}

	return DP[i][ey][ex][k] = dp(i-1, ey && (yv[i] == 1), ex && (xv[i] == 1), k-1) + dp(i-1, ey && (yv[i] == 0), ex && (xv[i] == 0), k);
}

void solve(){
	long long x_, y_, k, b;
	cin >> x_ >> y_ >> k >> b;
		
	int i = 0;
	while(x_){
		xv[i] = x_ % b;
		x_ /= b;
		i++;
	}
	i = 0;
	while(y_){
		yv[i] = y_ % b;
		y_ /= b;
		i++;
	}

	int q = i;

	// for(int i : xv) cout << i;
	// cout << endl;

	memset(DP, -1, sizeof(DP));
	cout << dp(q, 1, 1, k) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}