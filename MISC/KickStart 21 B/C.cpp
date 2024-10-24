#include <bits/stdc++.h>

#define N 100000000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1];
vector<long long> pr;

void solve(int q){
	long long n;
	long long ans = 0;
	scanf("%lld", &n);

	for(int i = 0; i < pr.size(); i++){
		if(1ll * pr[i] * pr[i+1] <= n){
			ans = pr[i] * pr[i+1];
		}
		else{
			break;
		}
	}

	printf("Case #%d: %lld\n", q, ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(long long i = 2; i <= N; i++){
		if(a[i] == 0){
			pr.push_back(i);
			int j = i;
			while(j <= N){
				a[j] = 1;
				j += i;
			}
		}
	}

	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}