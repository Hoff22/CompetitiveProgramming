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

long long myround(double x){
	if(x < 0){
		return (long long)floor(x);
	}
	else{
		return (long long)ceil(x);
	}
}

void solve(){
	long long k,n;
	scanf("%lld %lld", &n, &k);

	if(n == 1){
		printf("0\n");
		return;
	}

	n--;

	//long long x = 2*n - 1;
	//printf("%lld\n" ,1ll*-16 / 6);
	//printf("%lld\n", k + myround(1.0*(n - (k*(k+1)/2)) / k) );
	long long y = (n - (k*(k+1)/2));
	if(y >= 0){
		printf("%lld\n", k + y/k + (y % k));
	}
	else{
		printf("%lld\n", k - myround(1.0*y/k) + (y % k));
	}
	printf("\t%lld\n", y);
	printf("\t%lld\n", y/k);
	printf("\t%lld\n", y%k);
	// if(x < (k*(k+1)/2) * (k*(k+1)/2)){
	// 	printf("%lld\n", (long long)ceil(sqrt(x)));
	// }
	// else{
	// 	long long y = (n - (k*(k+1)/2));
	// 	printf("%lld\n", k + y/k + (y % k));
	// }


}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}