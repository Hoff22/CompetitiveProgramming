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

map<long long, long long> m;

int main(){
	
	long long n, k;
	scanf("%lld %lld", &n, &k);

	for(int i = 1; i <= n; i++){
		long long x, y;
		scanf("%lld %lld", &x, &y);
		m[x] += y;
	}

	long long ans = k;

	long long last = 0;
	for(auto f : m){
		if(k < f.first - last){
			break;
		}
		k -= (f.first - last);
		k += f.second;
		ans = k + f.first;
		last = f.first;
	}

	printf("%lld\n", ans);
    return 0;

}