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

int a[N+1];

void solve(){
	int n;
	scanf("%d", &n);
	
	map<int,int> cnt;

	int mx_cnt = 0;

	for(int i = 0; i < n; i++){
		scanf("%d", (a + i));
		cnt[a[i]]++;
		mx_cnt = max(mx_cnt, cnt[a[i]]);
	}

	int ans = 0;
	while(mx_cnt < n){
		ans++;
		ans += min(mx_cnt, n - mx_cnt);
		mx_cnt *= 2;
	}

	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}