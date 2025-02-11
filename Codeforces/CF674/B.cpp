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

int tiles[N+1][2][2];

void solve(){
	int n, m;
	scanf("%d %d", &n, &m);

	int center = 0;
	int mid = 0;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &tiles[i][0][0], &tiles[i][0][1], &tiles[i][1][0], &tiles[i][1][1]);

		if(tiles[i][1][0] == tiles[i][0][1]) center = 1;

		if(mid == 0){
			mid = 1;
			for(int j = 0; j < i; j++){
				for(int k = 0; k < 2; k++){
					for(int q = 0; q < 2; q++){
						if(tiles[i][k][q] != tiles[j][q][k]) mid = 0;
					}
				}
			}		
		}
	}

	if(m%2 or (!mid or !center)) printf("NO\n");
	else printf("YES\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}