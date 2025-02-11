#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	vector<int> a(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	sort(a.begin(), a.end());

	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += upper_bound(a.begin()+i+1, a.end(), r-a[i]) - lower_bound(a.begin()+i+1, a.end(), l-a[i]);
	}

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