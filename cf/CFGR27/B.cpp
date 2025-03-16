#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

typedef long long ll;

int p3[500][2];
int p6[500][2];

int DP[500][33][66];

int n;
int dp(int i, int r0, int r1){
	if(i < 0) return !(r0 or r1);

	if(DP[i][r0][r1] != -1) return DP[i][r0][r1];

	if(dp(i-1, (r0 + p3[i][0]) % 33, (r1 + p3[i][1]) % 66)) return DP[i][r0][r1] = dp(i-1, (r0 + p3[i][0]) % 33, (r1 + p3[i][1]) % 66);
	if(dp(i-1, (r0 + p6[i][0]) % 33, (r1 + p6[i][1]) % 66)) return DP[i][r0][r1] = dp(i-1, (r0 + p6[i][0]) % 33, (r1 + p6[i][1]) % 66);
	return DP[i][r0][r1] = 0;
}

vector<int> num;
void rec(int i, int r0, int r1){
	if(i < 0){
		return;
	}

	int tr = dp(i-1, (r0 + p3[i][0]) % 33, (r1 + p3[i][1]) % 66);

	if(tr){
		num.push_back(3);
		rec(i-1, (r0 + p3[i][0]) % 33, (r1 + p3[i][1]) % 66);
	}
	else{
		num.push_back(6);
		rec(i-1, (r0 + p6[i][0]) % 33, (r1 + p6[i][1]) % 66);
	}
}

void solve(){
	cin >> n;

	if(!dp(n-1, 0, 0)){
		cout << -1 << endl;
		return;
	}

	num.clear();

	rec(n-1, 0, 0);

	for(int i : num) cout << i;
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	for(int i = 0; i < 500; i++){
		for(int j = 0; j < 33; j++){
			for(int k = 0; k < 66; k++){
				DP[i][j][k] = -1;
			}
		}
	}

	for(int i = 0; i < 500; i++){
		p3[i][0] = (i % 2) ? 30 : 3;
		p3[i][1] = (i % 2) ? 30 : 36;
		
		p6[i][0] = (i % 2) ? 27 : 6; // mod 33
		p6[i][1] = (i % 2) ? 60 : 6; // mod 66
	}

	p3[0][1] = 3;

	while(t--){
		solve();
	}
    return 0;

}