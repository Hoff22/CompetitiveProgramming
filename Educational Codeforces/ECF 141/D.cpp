#include <bits/stdc++.h>

#define N 300
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int n;
int a[N+1];
long long seen[N+1][2*(N*N)+2];

long long solve(int i, int cur){

	if(i == n){
		return 1ll;
	}

	if(seen[i][cur+(N*N)] != -1) return seen[i][cur+(N*N)];

	if(cur == 0) return seen[i][cur+(N*N)] = solve(i+1, a[i+1]);

	return seen[i][cur+(N*N)] = (solve(i+1, a[i+1] - cur) + solve(i+1, a[i+1] + cur)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(seen, -1, sizeof(seen));

	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	printf("%lld\n", solve(2, a[2]) % MOD);

    return 0;

}