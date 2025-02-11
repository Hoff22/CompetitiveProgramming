#include <bits/stdc++.h>

#define N 262142
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

vector<long long> sqrs;

long long x[N+1];
long long cnt[N+1];

void solve(){
	long long n;
	scanf("%lld", &n);

	vector<long long> a(n+1);

	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}

	//for(long long i = 0; i <= N; i++) cnt[i] = 1;
	for(long long i = 0; i <= N; i++) cnt[i] = 0;

	x[0] = 0;
	for(long long i = 1; i <= n; i++) x[i] = x[i-1] ^ a[i];

	long long ans = n*(n+1)/2;

	cnt[0]++;
	for(long long i = 1; i <= n; i++){
		//prlong longf("%d: \n", i);
		for(long long sq : sqrs){
			ans -= cnt[x[i] ^ sq];
		}

		cnt[x[i]]++;
	}

	printf("%lld\n", ans);
}

/*

  4 4 4 4
0 4 0 4 0

  3 1 2
0 3 2 0 


*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
   	for(long long i = 0; i * i <= 262142; i++){
   		sqrs.push_back(i*i);
   	}

	long long t;
	scanf("%lld", &t);


	while(t--){
		solve();
	}
    return 0;

}