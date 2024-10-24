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

vector<int> primes;
void RangePrimes(int n){
	vector<int> v(n+1, 0);
	int i = 2;
	while(i <= n){
		if(v[i] == 0) primes.push_back(i);
		if(v[i] == 0 and i*i <= n){
			int j = i*i;
			while(j <= n){
				v[j] = 1;
				j += i;
			}
		}
		i++;
	}
}

int factor(int n){
	int factors = 0;
	for(int p : primes){
		while(n%p == 0){
			factors++;
			n /= p;
		}
		if(p*p > n) break;
	}
	if(n>1) factors++;
	return factors;
}

int af;
int bf;
int a, b, k;
 
void solve(){
 	
	int l;
	if(a == b){
		l = 0;
	}
	else if(a % b == 0 or b % a == 0){
		l = 1;
	}
	else{
		l = 2;
	}

	int r = af + bf;

	if(a == b and k == 1){
		printf("NO\n");
		return;
	}
	if(l <= k and k <= r) printf("YES\n");
	else printf("NO\n");
 
	return;
}
 
int main(){
	
	int t;
	scanf("%d", &t);
	
	RangePrimes(40000);

	while(t--){
		scanf("%d %d %d", &a, &b, &k);
 
		af = factor(a);
		bf = factor(b);
 
		solve();
	}
    return 0;
 
}