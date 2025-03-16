#include <bits/stdc++.h>

#define N 500000
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

long long x[N+1];
long long y[N+1];

vector<>

int quadrant(int a, int b){
	if(a > 0 and b > 0) return 1;
	if(a < 0 and b > 0) return 2;
	if(a < 0 and b < 0) return 3;
	if(a > 0 and b < 0) return 4;
	return 0;
}

int main(){
	
	long long ox, oy, r, n;
	scanf("%lld %lld %lld %lld", &ox, &oy, &r, &n);

	for(int i = 0; i < n; i++){
		long long a, b;
		scanf("%lld %lld", &a, &b);

		x[i] = a-ox;
		y[i] = b-oy;
	}

	long long ans = 0;
	for(int i = 0; i < n; i++){
		long long dist = 1ll * (x[i]*x[i]) + (y[i]*y[i]);
		if(dist <= 1ll*r*r){
			ans++;
		} 
	}

	printf("%lld\n", ans);


    return 0;

}