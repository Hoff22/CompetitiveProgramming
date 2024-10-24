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

	vector<int> a(n+1);

	int l = 0;
	int r = 0;

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		r += (a[i] == 2);
	}

	for(int i = 1; i < n; i++){
		l += (a[i] == 2);
		r -= (a[i] == 2);
		if(l == r){
			printf("%d\n", i);
			return;
		}
	}

	printf("-1\n");
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