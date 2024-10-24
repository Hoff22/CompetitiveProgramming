#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

long long d10[19];

void solve(){
	long long n;
	scanf("%lld", &n);

	vector<int> a(19);
	int i = 0;
	vector<int> res(19);
	while(n){
		int d = n%10;

		if(d == 0){
			n -= 10;
			d = 10;
		}

		int x = 0;
		while(d >= 3){
			d -= 3;
			x++;
		}

		if(d) res[i]++;
		a[i] = x;

		n /= 10;
		i++;
	}
	
	long long ans = 0;
	for(int j = 0; j < 19; j++){
		ans = max(ans, (long long)a[j]);
	}
	for(int j = 1; j < 19; j++){
		res[j] = max(res[j], res[j-1]);
	}

	printf("%lld\n", ans + res[18]);


}

int main(){
	
	int t;
	scanf("%d", &t);

	d10[0] = 1;
	for(int i = 1; i < 19; i++){
		d10[i] = d10[i-1] * 10;
	}

	while(t--){
		solve();
	}
    return 0;

}