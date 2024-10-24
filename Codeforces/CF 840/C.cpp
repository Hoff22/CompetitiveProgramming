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

	vector<long long> a(n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}	


	long long mx = *max_element(a.begin(), a.end());

	/*

* * * * 
  ^             

1 1 2


	*/

	if(n == 2ll){
		printf("%lld\n", max(1ll*a[0] + a[1], 2ll* abs(a[0] - a[1])));
	}
	else if(n == 3ll){
		printf("%lld\n", max({
			1ll*a[0]+a[1]+a[2],
			1ll*abs(a[0]-a[1])*2 + a[2],
			1ll*abs(a[1]-a[2])*2 + a[0],
			1ll*abs(a[0]-a[2])*3,
			1ll*a[0]*3,
			1ll*a[2]*3,
			1ll*abs(a[0]-a[1])*3,
			1ll*abs(a[1]-a[2])*3
		}));
	}
	else{
		printf("%lld\n", 1ll*n*mx);
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