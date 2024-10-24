#include <bits/stdc++.h>

#define N 15
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

vector<int> v[N+1];
vector<int> arr[N+1];

int cost[N+1][N+1];

int dp[(1<<15)][N+1];

bool contains(int a, int b){
	for(int i = 0; i < v[b].size(); i++){
		int j;
		for(j = 0; j < v[a].size(); j++){
			if(i+j >= v[b].size()) break;	
			if(v[a][j] != v[b][i+j]) break;
		}
		if(j >= v[a].size()) return true;
	}
	return false;
}

int calcC(vector<int>& a, vector<int>& b){

	for(int i = 0; i < a.size(); i++){
		int j;
		for(j = 0; j < b.size(); j++){
			if(i + j >= a.size()) return b.size() - j;
			if(a[i+j] != b[j]) break;
		}
	}

	return b.size();

}

int k = 0;
int solve(int used, int last){

	if(used == ((1<<k) - 1)){
		return 0;
	}

	if(dp[used][last] != -1) return dp[used][last];

	int r = INF;
	for(int i = 0; i < k; i++){
		if(!((used>>i) & 1)){
			r = min(r, solve(used | (1<<i), i) + cost[last][i]);
		}
	}

	return dp[used][last] = r;
}

// 1 2 3 4 5 6
//         5 6 7 8 9
//       4 5 6 7 8 9 10
//               8 9 10 11

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int m;
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			int x; 
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}
	

	for(int i = 0; i < n; i++){
		int good = 1;
		for(int j = 0; j < n; j++){
			if(v[i].size() <= v[j].size()){
				if(i != j and contains(i, j)){
					//printf("%d %d\n", i, j);
					good = 0;
				}
			}
		}
		if(good){
			arr[k] = v[i];
			k++;
		}
	}

	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			cost[i][j] = calcC(arr[i], arr[j]);
		}
	}


	if(k == 0){
		printf("%d\n", (int)v[0].size());
		return 0;
	}

	int ans = INF;

	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < k; i++){
		ans = min(ans, solve((1<<i), i) + (int)arr[i].size());
	}

	printf("%d\n", ans);

    return 0;

}