#include <bits/stdc++.h>

#define N 100000
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

int a[N + 1]; // (Input)
int n;

void solve(){
	int k;
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	int p = 0;
	for(int i = 1 ; i <= n; i++){
		if((p+1) == a[i]){
			p++;
		}
	}

	printf("%d\n", (int)ceil((1.0 * n - p) / k));
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