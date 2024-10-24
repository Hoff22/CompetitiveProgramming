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


int n, m;
map<int, vector<int>> columns;
map<pair<int,int>, int> dp;

int getI(int i, int j){

	if(!columns.count(j)) return -1;

	int r = lower_bound(columns[j].begin(), columns[j].end(), i) - columns[j].begin() - 1;

	if(r < 0 or r > columns[j].size()-1){
		return -1;
	}

	return columns[j][r];
}

int solve(int i, int j){
	
	if(i == -1) return 0;
	if(j == n and i == 0) return 1;

	if(dp.count({i,j})) return dp[{i,j}];

	int left = solve(getI(i, j-1), j-1);
	int right = solve(getI(i, j+1), j+1);

	return dp[{i,j}] = (left or right);
}

int main(){
	
	scanf("%d %d", &n, &m);

	for(int k = 0; k < m; k++){
		int i, j;
		scanf("%d %d", &i, &j);

		columns[j].push_back(i);
	}

	columns[n].push_back(0);

	for(auto& j : columns){
		sort(j.second.begin(), j.second.end());
	}

	int ans = 0;
	for(auto j : columns){
		ans += solve(j.second.back(), j.first);
	}

	printf("%d\n", ans);

    return 0;

}