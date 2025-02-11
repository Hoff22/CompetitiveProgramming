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

vector<long long> factor(long long n){
	vector<long long> factors;
	if(n == 1){
		factors.push_back(1);
		return factors;
	}
	long long i = 2;
	while(i*i <= n){
		while(n%i == 0){
			factors.push_back(i);
			n /= i;
		}
		i++;
	}
	if(n>1) factors.push_back(n);
	return factors;
}

// 105  5
// 21   7
// 3    3
// 1

// (k*n)+1210

int ans[N+1];

int main(){
	
	int n;
	scanf("%d", &n);
	
	long long p = 1;
	int count = 1;
	for(int i = 2; i < n; i++){
		if(n % i == 0 and ans[i] == 0){
			int j = 1;
			while(i*j < n){
				ans[i*j] = -1;
				j++;
			}
		}
		if(ans[i] == 0){
			p = (1ll*p*i) % n;
			count++;
		}
	}

	if(p == 1){
		printf("%d\n", count);
		for(int i = 1; i < n; i++) if(ans[i] == 0) printf("%d ", i);

		printf("\n");
	}
	else{
		printf("%d\n", count-1);
		for(int i = 1; i < n; i++) if(ans[i] == 0 and i != p) printf("%d ", i);
		printf("\n");
	}

    return 0;

}