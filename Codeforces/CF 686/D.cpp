#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define fi first
#define se second

using namespace std;

bool isPrime(long long n){
	for(long long i = 2; i * i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

map<long long,int> fac(long long x){
	map<long long,int> facts;

	for(long long i = 2; i * i <= x; i++){
		while(x % i == 0){
			x /= i;
			facts[i]++;
		}
	}

	return facts;
}

void solve(){
	long long n;
	scanf("%lld", &n);

	if(isPrime(n)){
		printf("1\n");
		printf("%lld\n", n);
		return;
	}
// 360
// 180
// 90
	map<long long,int> f = fac(n);

	long long mx = 1;
	for(auto x : f){
		if(x.se > f[mx]) mx = x.fi;
	}

	printf("%d\n", f[mx]);

	for(int i = 0; i < f[mx]-1; i++){
		printf("%lld ", mx);
		n /= mx;
	}

	printf("%lld\n", n);

}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}

    return 0;

}