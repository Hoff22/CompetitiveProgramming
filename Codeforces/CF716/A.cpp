#include <bits/stdc++.h>

#define N 100
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N];

int n;

void solve(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	map<int,int> factors;

	for(int i = 0; i < n; i++){
		long long f = 2;

		while(f*f <= a[i]){
			while(a[i]%f == 0){

				factors[f]++;
				a[i] /= f;
			}

			if(factors[f] % 2){
				printf("YES\n");
				return;
			}

			f++;
		}
		if(a[i] > 1){
			factors[a[i]]++;
			if(factors[a[i]] % 2){
				printf("YES\n");
				return;
			}
		}
	}

	printf("NO\n");
}

int main(){

	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= 10000; i++){
		sq.insert(i*i);
	}

	while(t--){
		solve();
	}
    return 0;

}