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
	int n, s;
	scanf("%d %d", &n, &s);

	set<int> p;
	for(int i = 1; i <= 1000; i++){
		p.insert(i);
	}

	int mx = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		mx = max(mx, x);
		p.erase(x);
	}
// 1 2 3 4
//     3 4
	int cur = 0;
	for(int i : p){
		if(cur == s and i > mx){
			printf("YES\n");
			return;
		}
		cur += i;
		//printf("%d %d\n", i, cur);
		if(cur > s) break;
	}
	if(cur == s){
		printf("YES\n");
		return;
	}

	printf("NO\n");
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