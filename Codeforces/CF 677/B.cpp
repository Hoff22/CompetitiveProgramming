#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> v(n);
	int l = -1;
	int r = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		if(v[i] and l == -1) l = i;
		if(v[i]) r = i;
	}

	int ans = 0;
	for(int i = l; i < r; i++){
		if(v[i] == 0) ans++;
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