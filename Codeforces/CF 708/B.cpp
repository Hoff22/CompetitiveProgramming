#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define L 0
#define R 1

using namespace std;

int a[N];

void solve(){
	int n, m;
	long long ans = 0;
	scanf("%d %d", &n, &m);

	memset(a, 0, sizeof(a));

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		a[x%m]++;
	}

	for(int i = 1; i < m; i++){
		if(a[i] or a[m-i]){
			if(a[i] < a[m-i]) swap(a[i], a[m-i]); 
			if(a[i] == a[m-i] or a[i] == a[m-i]+1){
				ans++;
			}
			else{
				if(a[m-i]){
					ans++;
					a[i] -= a[m-i] + 1;
				}
				ans += a[i];
			}
			a[i] = a[m-i] = 0;
		}
	}

	if(a[0]) ans++;

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