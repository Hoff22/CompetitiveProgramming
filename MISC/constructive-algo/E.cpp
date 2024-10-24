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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int a[4] = {0,0,0,0};
	char b[4] = {'A','B','C','D'};
	scanf("%d %d %d %d", a, (a+1),(a+2),(a+3));

	vector<vector<int>> ans;

	for(int n = 1; n <= 50; n++){
		for(int m = 1; m <= 50; m++){
			vector<vector<int>> cur(n+1, vector<int>(m+1, 0));
			int c[4] = {a[0],a[1],a[2],a[3]};
			int k = 0;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){

					if(c[0]+c[1]+c[2]+c[3] == 0){
						goto f;
					}

					while(c[k] == 0) k = (k+1)%4;
					cur[i][j] = b[k];
					if(cur[i][j-1] != cur[i][j] and cur[i-1][j] != cur[i][j]){
						c[k]--;
					}

					k = (k+1)%4;
				}
			}

			if(c[0]+c[1]+c[2]+c[3] == 0){
				ans = cur;
				goto f;
			}
		}
	}
	f:
	for(int i = 1; i < ans.size(); i++){
		for(int j = 1; j < ans[i].size(); j++){
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}