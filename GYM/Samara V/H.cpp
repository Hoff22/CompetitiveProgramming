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

vector<int> a(9);
vector<int> w(9);

map<vector<int>, long long> dp;
set<vector<int>> seen;

bool valid(vector<int> state){
	bool good = 1;
	if(state[8] != 0) good = 0;
	for(int i = 1; i < 8; i++){
		if(state[i] < state[i-1]) good = 0;
	}
	return good;
}

int findzero(vector<int> state){
	for(int i = 0; i < 9; i++){
		if(state[i] == 0) return i;
	}
	return -1;
}

long long solve(vector<int> state){

	if(valid(state)) return 0;

	// for(int i = 0; i < 9; i++){
	// 	printf("%d ", state[i]);
	// }
	// printf("\n");

	if(seen.count(state)) return dp[state];
	seen.insert(state);

	int index = findzero(state);

	long long r = INFll;

	if(index % 3 == 0 or index % 3 == 1){ // pode ir pra direita
		swap(state[index], state[index+1]);
		r = min(r, w[state[index]] + solve(state));
		swap(state[index], state[index+1]);
	}
	if(index % 3 == 2 or index % 3 == 1){ // pode ir pra esquerda
		swap(state[index], state[index-1]);
		r = min(r, w[state[index]] + solve(state));	
		swap(state[index], state[index-1]);
	}
	if(index + 3 < 9){// pode ir pra baixo
		swap(state[index], state[index+3]);
		r = min(r, w[state[index]] + solve(state));	
		swap(state[index], state[index+3]);
	}
	if(index - 3 >= 0){// pode ir pra cima
		swap(state[index], state[index-3]);
		r = min(r, w[state[index]] + solve(state));	
		swap(state[index], state[index-3]);
	}

	return dp[state] = r;
}

int main(){
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &a[i*3+j]);
		}
	}

	for(int i = 1; i <= 8; i++){
		scanf("%d", &w[i]);
	}

	printf("%lld\n", solve(a));
	
    return 0;

}