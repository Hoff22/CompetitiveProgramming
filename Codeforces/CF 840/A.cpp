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
	int n;
	scanf("%d", &n);

	vector<int> cnt(11,0);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		int j = 0;
		while(x){
			cnt[j] += (x&1);
			x >>= 1;
			j++;
		}
	}

	// for(int i = 0; i <= 10; i++){
	// 	printf("%d ", cnt[i]);
	// }
	// printf("\n");

	int mx = 0;
	int mn = 0;
	int p = 1;
	for(int i = 0; i <= 10; i++){
		if(cnt[i]){
			mx += p; 
		}
		if(cnt[i] == n){
			mn += p; 
		}
		p*=2;
	}

	//printf("%d %d\n", mx, mn);

	printf("%d\n", mx - mn);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}