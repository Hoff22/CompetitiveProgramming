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

void solve(){
	int n;
	vector<long long> c;
	scanf("%d", &n);

	c.push_back(0);
	for(int i = 1; i <= n; i++){
		long long x;
		scanf("%lld", &x);

		c.push_back(x);
	}

	int i = 1;
	long long sum = 0;
	long long mn1 = c[1];
	long long mn2 = c[2];
	long long best = numeric_limits<long long>::max();;
	while(i < c.size()){

		if(i%2){
			mn1 = min(mn1, c[i]);
		}
		else{
			mn2 = min(mn2, c[i]);
		}
		sum += c[i];

		best = min(best, sum + mn1*(n - (i+1)/2) + mn2*(n - i/2));
		
		i++;
	}

	printf("%lld\n", best);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}