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
	int n, w, h;
	scanf("%d %d %d", &n, &w, &h);

	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	int rMove = 0;

	for(int i = 0; i < n; i++){
		int rC = a[i]+w;
		int rD = b[i]+h;
		rMove = max(rMove, rD - rC);
	}
		// printf("move pra direita: %d\n", rMove);

	if(rMove){
		for(int i = 0; i < n; i++){
			int lC = rMove+a[i]-w;
			int rC = rMove+a[i]+w;
			int lD = b[i]-h;
			int rD = b[i]+h;
			if(lC > lD or rD > rC){
				printf("NO\n");
				return;
			}
		}

		printf("YES\n");
		return;
	}
	else{
		for(int i = 0; i < n; i++){
			int lC = a[i]-w;
			int lD = b[i]-h;
			rMove = max(rMove, lC - lD);
		}
		// printf("move pra esquerda: %d\n", rMove);
		for(int i = 0; i < n; i++){
			int lC = a[i]-w-rMove;
			int rC = a[i]+w-rMove;
			int lD = b[i]-h;
			int rD = b[i]+h;
			if(lC > lD or rD > rC){
				// printf("%d %d %d %d\n", lC, rC, lD, rD);
				printf("NO\n");
				return;
			}
		}

		printf("YES\n");
		return;
	}
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