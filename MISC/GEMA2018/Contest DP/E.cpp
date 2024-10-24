#include <bits/stdc++.h>

#define N 1000000000000000000ll
#define K 18
#define INF 0x3f3f3f3f

using namespace std;

long long power10[K+1];

long long biggest;
int n, m;
long long l, r;

long long dp[K+1][2][K+1][K+1];

long long solve(int i, bool is_smaller, int qnt_7, int qnt_4){
	if(i < 0){
		return (qnt_4 == n or qnt_7 == m);
	}

	long long& ans = dp[i][is_smaller][qnt_7][qnt_4];

	if(ans != -1){
		return ans;
	}

	ans = 0;

	if(is_smaller){
		for(int d = 0; d <= 9; d++){
			ans += solve(i - 1, true, qnt_7 + (d == 7), qnt_4 + (d == 4));
		}
	}
	else{
		int dn = (biggest / power10[i]) % 10;

		for(int d = 0; d <= dn; d++){
			ans += solve(i - 1, d < dn, qnt_7 + (d == 7), qnt_4 + (d == 4));
		}
	}

	return ans;

}

int main(){

	power10[0] = 1;


	for(int i = 1; i <= K; i++){
		power10[i] = power10[i-1] * 10;
	}

	cin >> n >> m >> l >> r;

	biggest = l - 1;

	memset(dp, -1, sizeof(dp));
	long long solveL = solve(K, false, 0, 0);

	biggest = r;

	memset(dp, -1, sizeof(dp));
	long long solveR = solve(K, false, 0, 0);

	cout << solveR - solveL << endl;

    return 0;
}
