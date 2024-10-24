#include <bits/stdc++.h>

#define N 100000
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

bool seen[N+1];

void solve(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++){
		seen[i] = 0;
	}

	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		seen[b] = true;
	}

	int root;
	for(int i = 1; i <= n; i++){
		if(seen[i] == 0){
			root = i;
			break;
		}
	}

	for(int i = 1; i <= n; i++){
		if(i != root){
			printf("%d %d\n", root, i);
		}
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}