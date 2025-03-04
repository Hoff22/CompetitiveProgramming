#include <bits/stdc++.h>

// 21:27

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

	for(int i = 0; i < n; i++){
		scanf("%*d");
	}
	int p = 10 - n;
	long long l = (p*(p-1) * 4 * 3) / 4;

	printf("%lld\n", l);
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