#include <bits/stdc++.h>

#define N 2000
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
int freq[N+1];
int ans[N+1][N+1];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		ans[0][i] = a[i];
	}

	int last = 0;
	for(int k = 1; k <= 100000000; k++){
		memset(freq, 0, sizeof(freq));
		for(int i = 1; i <= n; i++){
			freq[a[i]]++;
		}
		int complete = 1;
		for(int i = 1; i <= n; i++){
			if(a[i] != freq[a[i]]) complete = 0;
			a[i] = freq[a[i]];
			ans[k][i] = a[i];
		}
		if(complete){
			last = k;
			break;
		}
	}

	int q;
	scanf("%d", &q);

	while(q--){
		int x, k;
		scanf("%d %d", &x, &k);

		printf("%d\n", ans[min(last, k)][x]);
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