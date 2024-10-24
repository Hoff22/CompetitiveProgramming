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
	long long n, s;
	scanf("%lld %lld", &n, &s);

	long long tmp = n;
	int sum = 0;
	while(tmp){
		sum += tmp%10;
		tmp/=10;
	}

	if(sum <= s){
		printf("0\n");
		return;
	}

	long long ans = 0;
	int i = 0;
	int carry = 0;
	while(n/d10[i] > 0){
		int d = (n/d10[i])%10;

		if(d){
			sum -= d;
			ans += (10-d-carry)*d10[i];
			if(!carry){
				sum += 1;
			}
			carry = 1;
			//printf("%d %lld %d\n", d, ans, sum);
		}
		else{
			if(carry){
				ans += 9*d10[i];
			}
		}

		i++;
		if(sum <= s) break;
	}
	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	d10[0] = 1;
	for(int i = 1; i <= 18; i++){
		d10[i] = d10[i-1] * 10;
	}

	while(t--){
		solve();
	}
    return 0;

}