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

int freq[31];
void solve(){
	int n;
	scanf("%d", &n);

	memset(freq, 0, sizeof(freq));

	int sum = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		int j = 0;
		while(x){
			freq[j] += (x & 1);
			sum += freq[j];
			x/=2;
			j++;
		}
	}

	if(sum == 0){
		for(int i = 1; i <= n; i++){
			printf("%d ", i);
		}
		printf("\n");
		return;
	}

	int mx = 0;
	for(int i = 0; i <= 30; i++){
		mx = __gcd(mx, freq[i]);
	}

	for(int i = 1; i <= mx; i++){
		if(mx % i == 0) printf("%d ", i);
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}