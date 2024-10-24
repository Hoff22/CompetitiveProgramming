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

	vector<long long> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

	sort(a.begin() + 1, a.end());
	
	for(int i = 1; i < n; i++){
		if(a[i] > a[0]){
			long long x = a[i] - a[0];

			a[0] += (x+1) / 2; 
		}		
	}

	printf("%lld\n", a[0]);
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