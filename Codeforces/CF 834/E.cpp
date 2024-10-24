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
	int n, h;
	scanf("%d %d", &n, &h);

	vector<long long> a(n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	sort(a.begin(), a.end());

	long long d[3] = {2ll, 2ll, 3ll};

	int ans = 0;

	do{
		int p = 0;
		int i = 0;
		long long h_ = h;
		while(i < n){
			if(a[i] < h_){
				h_ += a[i]/2;
				i++;
			}
			else if(p < 3){
				h_ *= d[p];
				p++;
			}
			else break;
		}

		ans = max(ans, i);
	}while(next_permutation(d, d+3));

	printf("%d\n", ans);
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