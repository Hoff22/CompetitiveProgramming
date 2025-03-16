#include <bits/stdc++.h>
// 22:49
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

long long a[N + 2]; // (input) an array of data to operate querys and updates over

void solve(){
	int n;
	scanf("%d", &n);

	int start = 0;
	vector<int> b(n+2);
	for(int i = 1; i <= n; i++){
		char c;
		scanf(" %c ", &c);
		b[i] = (c == '1');
		if(b[i] == 0 and start == 0) start = i;
	}

	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}

	a[0] = -INF;
	b[n+1] = 0;

	long long ans = 0;

	for(int i = 1; i < start; i++) ans += a[i];

	for(int i = start; i <= n; i++){
		//printf("%d:\n", i);
		if(b[i]){
			int j = i;
			int best = -1;
			
			long long r = 0;

			for(; j <= n and b[j] == 1; j++){
				if(best == -1) best = j;
				if(a[best] > a[j]) best = j;
				r += a[j];
			}

			if(a[i-1] > a[best]){
				ans += (r - a[best]) + a[i-1];
			}
			else{
				ans += r;
			}

			i = j;
		}
	}

	printf("%lld\n", ans);
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