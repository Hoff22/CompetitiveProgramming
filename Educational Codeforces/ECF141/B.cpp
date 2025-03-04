#include <bits/stdc++.h>

#define N 51
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

	int a[N][N];

	int i = 0;
	int j = 0;
	int t = 0;
	int k = 0;
	int p = 1;
	int g = n*n;
	while(t < n and k < n){
		//printf("t %d k %d\n", t ,k);
		while(i >= 0 and j < n){
			//printf("%d %d\n", i, j);
			if((i + j) % 2 == 0){
				a[i][j] = p;
				p++;
			}
			else{
				a[i][j] = g;
				g--;
			}
			i--;
			j++;
		}
		if(t < n-1){
			t++;
		}
		else{
			k++;
		}
		i = t;
		j = k;
	}

	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++){
			printf("%d ", a[r][c]);
		}
		printf("\n");
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