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
	long long n;
	scanf("%lld", &n);

	long long sum = (n + 1) * n / 2;

	long long x = 2 * n;

	// x * x - sum = y;

	long long y = x*x - (sum + (n+1));

	long long sum_to_second_last = y % n;

	long long sum_to_last = n+1;

	long long sum_to_everyone = y / n;

	for(long long i = 1; i <= n; i++){
		long long c = i + sum_to_everyone;

		if(i == n-1) c += sum_to_second_last;
		if(i == n) c += sum_to_last;

		printf("%lld%c", c, " \n"[i==n]);
	}  
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}