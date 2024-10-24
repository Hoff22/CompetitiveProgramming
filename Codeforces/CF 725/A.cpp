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
	int n;
	scanf("%d", &n);


	int mx = 0;
	int idxmx = 0;
	int mn = INF;
	int idxmn = 0;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);

		if(mx < x){
			mx = x;
			idxmx = i;
		}
		if(mn > x){
			mn = x;
			idxmn = i;
		}
	}


	int distmn = min(n - idxmn+1, idxmn);
	int distmx = min(n - idxmx+1, idxmx);

	int distB = min(abs(idxmx - idxmn)+distmx, abs(idxmx - idxmn)+distmn);

	printf("%d\n", min(distmx + distmn, distB));
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}