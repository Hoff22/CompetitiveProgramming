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

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[N+1];
	for(int i = 0; i < n; i++){
		scanf("%d", (arr+i));
	}

	int freq[31];
	memset(freq, 0, sizeof(freq));

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 30; j++){
			freq[j] += ((arr[i] >> j) & 1);
		}
	}

	long long ans = 0;
	for(int j = 30; j >= 0; j--){
		if(n - freq[j] <= k){
			ans |= (1<<j);
			k -= (n - freq[j]);
		}
	}
	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}