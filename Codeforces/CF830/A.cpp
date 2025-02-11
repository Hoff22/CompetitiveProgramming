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

	int g = 0;
	vector<int> v(n+1);
	vector<int> c(n+1);

	for(int i = 1; i <= n; i++){

		scanf("%d", &v[i]);
		
		if(v[i] == gcd(v[i], i)) c[i] = 0;
		else{
			c[i] = n-i+1;
		}
	}

	g = v[1];
	for(int i = 2; i <= n; i++){
		g = gcd(v[i], g);
	}

	if(g == 1){
		printf("0\n");
		return;
	}

	int best = n;
	for(int i = n; i >= 2; i--){
		if(gcd(gcd(v[i], i), g) == 1){
			best = min(best, c[i]);
		}

		best = min(best, c[i] + c[i-1]);
	}

	printf("%d\n", best);

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