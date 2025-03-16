#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

vector<int> v;
int n;
int fullSum;

int dp[100][100001];

long long solve(int i, int sum){

	if(i >= n){
		return max(sum, fullSum-sum);
	}

	if(dp[i][sum] != -1) return dp[i][sum];

	return dp[i][sum] = min(solve(i+1, sum+v[i]), solve(i+1, sum));
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		v.push_back(x);
	}

	fullSum = accumulate(v.begin(), v.end(), 0);

	memset(dp, -1, sizeof(dp));

	printf("%lld\n", solve(0,0));

    return 0;

}