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

	int a[N+1];
	int b[N+1];

	for(int i = 0; i < n; i++){
		scanf("%d", (a+i));
	}
	for(int i = 0; i < n; i++){
		scanf("%d", (b+i));
	}

	long long sum = 0;

	for(int i = 1; i < n; i++){
		if(abs(a[i-1] - a[i]) + abs(b[i-1] - b[i]) > abs(a[i-1] - b[i]) + abs(b[i-1] - a[i])) swap(a[i], b[i]);

		sum += abs(a[i-1] - a[i]) + abs(b[i-1] - b[i]);
	}

	printf("%lld\n", sum);
	
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}