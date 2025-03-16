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

int k;
int n;

long long p10[11];

int cnt(int x){
	int r = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(i + j == x and i != j) r++;
		}
	}

	return r + (x%2 == 0);
}

void solve(){
	scanf("%d", &n);

	long long ans = 0;
		
	k = 0;
	int tmp = n;
	while(tmp){
		k++;
		tmp/=10;
	}

	if(k > 2){
// (d-1-(d%2)) * antes + (d+1) * antes + (if n/p10[2] > 0){  } 
		for(long long m = 0; m < (1<<(k-2)); m++){
			int i = 0;
			long long mask = (m<<2);
			long long cur = 1;
			while(n/p10[i] > 0){

				int d = (n/p10[i]) % 10;

				if(((mask>>(i+2)) & 1) and ((mask>>i)&1)) cur *= cnt(10+d-1);
				else if((mask>>(i+2)) & 1) cur *= cnt(10+d); 
				else if((mask>>i)&1) cur *= cnt(d-1);
				else cur *= cnt(d);
				i++;
			}

			ans += cur;
		}
	}
	else{
		int i = 0;
		long long cur = 1;
		while(n/p10[i] > 0){

			int d = (n/p10[i]) % 10;

			cur *= cnt(d);
			i++;
		}

		ans += cur;
	}

	printf("%lld\n", ans-2);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	p10[0] = 1;
	for(int i = 1; i <= 10; i++) p10[i] = p10[i-1]*10;

	while(t--){
		solve();
	}
    return 0;

}