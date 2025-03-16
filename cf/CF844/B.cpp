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
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	sort(a.begin()+1, a.end());

	vector<int> b(n+1, 0);

	int ans = 0;
	int cur = 0;
	for(int i = 1; i <= n; i++){
		b[i] = (cur >= a[i]);
		cur++;
	}

	for(int i = 1; i <= n; i++){
		if(b[i] == 1 and b[i-1] == 0){
			ans++;
		}
	}

	if(a[1] != 0) ans++;

	printf("%d\n", ans);
}
/*

0 2 3 3 6 6 7 7

2 2 3 4 4


*/


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