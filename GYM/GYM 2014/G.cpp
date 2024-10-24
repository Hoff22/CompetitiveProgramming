#include <bits/stdc++.h>

#define N 300
#define MAX 100000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

vector<int> rows[N+1];
vector<int> columns[N+1];

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++){
		rows[i].assign(m+1,0);
		for(int j = 1; j <= m; j++){
			int x;
			scanf("%d", &x);
			rows[i][j] = x;
		}
	}

	for(int j = 1; j <= m; j++){
		columns[j].assign(n+1,0);
		for(int i = 1; i <= n; i++){
			columns[j][i] = rows[i][j];
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int mndx = i;
		for(int j = i+1; j <= n; j++){
			if(rows[j][1] < rows[mndx][1]) mndx = j;
		}
		if(i != mndx){
			ans++;
			swap(rows[i], rows[mndx]);
		}
	}

	for(int i = 1; i <= m; i++){
		int mndx = i;
		for(int j = i+1; j <= m; j++){
			if(columns[j][1] < columns[mndx][1]) mndx = j;
		}
		if(i != mndx){
			ans++;
			swap(columns[i], columns[mndx]);
		}
	}

	int good = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= m; k++){
				int dif = abs(rows[i][j] - rows[i][k]);
				if(dif > m-1){
					good = 0;
				}
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				int dif = abs(columns[i][j] - columns[i][k]);
				if(dif % m != 0){
					good = 0;
				}
			}
		}
	}

	if(good) printf("%d\n", ans);
	else printf("*\n");
	
    return 0;

}