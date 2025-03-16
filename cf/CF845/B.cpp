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

long long fact[N+1];
long long n;

void initFact(){
	fact[0] = 1;
	for(long long i = 1; i <= N; i++){
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

void solve(){
	scanf("%lld", &n);

	long long ans = 0;

	ans = (fact[n] * ((n * (n-1)) % MOD)) % MOD;

	printf("%lld\n", ans);
}

/*
389456655
74687312
74849012

1 2 | 2 1

2 1 | 1 2


(n+1) * n - (n*(n+1)/2)

n-0 + n-1 + n-2 ... + n-n


n-0 + n-1 + n-2


1 2 3 4

2:
 1 4 2 3
 2 1 4 3
 1 3 4 2
 3 1 2 4
 2 3 1 4
 
3:
 3 2 1 4


1 2 3 4 5

1 3 2 4 5

kinvs = n * (n-1) 


1 2

1:

 2 1


1 2 3

1 :
 2 1 3
 1 3 2

2:
 2 3 1
 3 1 2

3:
 3 2 1




*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	initFact();
	
	while(t--){
		solve();
	}
    return 0;

}