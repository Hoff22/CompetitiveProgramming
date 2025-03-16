#include <bits/stdc++.h>

#define N 300000
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

	int h[N+1];

	int mx = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", (h + i));
		mx = max(mx, h[i]);
	}

	long long sum = 0;
	int pr = 0;

	for(int i = 0; i < n; i++){
		if(h[i] == mx) continue;

		sum += (mx - h[i]);
		if((mx - h[i]) % 2) pr++;
	}

	sum -= max(0, (pr + 2*(pr-1)));

	int ans = max(0, pr * 2 - 1);
	
	if(sum <= 0){
		printf("%d\n", ans);
		return;
	}
	else{
		ans += ((sum / 6) * 4);
		sum = sum % 6;

		int i = 0;
		while(sum > 0){
			sum -= (1 + (i % 2 == 0));
			i++;
			ans++;
		}

		printf("%d\n", ans);
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