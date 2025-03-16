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

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	} 

	sort(v.begin(), v.end());

	int ans = v[0];
	for(int i = 0; i < n - 1; i++){
		ans = max(ans, v[i+1] - v[i]);
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