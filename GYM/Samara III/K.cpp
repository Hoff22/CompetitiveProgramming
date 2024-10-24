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

bool inside(int i, int j){
	return (i >= 0 and i <= 2 and j >= 0 and j <= 2);
}

vector<pair<int,int>> dir = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0, 0}, {0, 1}, {1,-1}, {1, 0}, {1, 1}};

int a[3][3];

long long dfs(int i, int j, int x, vector<vector<int>> arr){
	if(x == 9) return 1;

	arr[i][j] = x;

	long long r = 0;
	for(auto d : dir){
		int ni = i+d.fi;
		int nj = j+d.se;
		
		if(inside(ni, nj)){

			if(arr[ni][nj] == 0 or arr[ni][nj] == x+1){
				r += dfs(ni, nj, x+1, arr);
			}
		}
	}

	return r;
}

int main(){
	
	int n = 3;

	int i1, j1;
	i1 = j1 = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			scanf(" %c", &c);

			int x = c - '0';

			a[i][j] = x;

			if(a[i][j] == 1){
				i1 = i;
				j1 = j;
			}
		}
	}

	vector<vector<int>> vec;

	for(int i = 0; i < 3; i++){
		vector<int> aux;
		for(int j = 0; j < 3; j++){
			aux.push_back(a[i][j]);
		}
		vec.push_back(aux);
	}

	if(i1 != -1){
		printf("%lld\n", dfs(i1, j1, 1, vec));
	}
	else{
		long long ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j] == 0){
					ans += dfs(i, j, 1, vec);
				}
			}
		}
		printf("%lld\n", ans);
	}

    return 0;

}