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

	int ans = 0;
	for(int i = 0; i < n; i++){
		int of = mx - h[i];
		ans += (of % 2) + (of - (of % 2)) / 3 + (of - (of % 2)) / 3 
	}

	

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}