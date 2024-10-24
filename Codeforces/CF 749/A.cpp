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

int a[N+1];

bool isPrime(long long n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}

void solve(){
	int n;
	scanf("%d", &n);

	long long sum = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	if(isPrime(sum)){
		int idx = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] % 2){
				idx = i;
				break;
			}
		}	
		printf("%d\n", n-1);
		for(int i = 1; i <= n; i++){
			if(i != idx) printf("%d ", i);
		}
		printf("\n");
	}
	else{
		printf("%d\n", n);
		for(int i = 1; i <= n; i++){
			printf("%d ", i);
		}
		printf("\n");
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}