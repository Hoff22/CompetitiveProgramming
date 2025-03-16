#include <bits/stdc++.h>

#define N 100
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

int a[N+1][N+1];
int n;

double solve(int i){
	if(i > n) return 1;

	double r = 0;
	for(int j = 1; j <= n; j++){
		r = max(r, (1.0*a[i][j]/100) * solve(i+1));
	}

	return r;
}

vector<int> reconstruct(int i){

	vector<int> ans;

	if(i > n) return ans;

	int next = 0;
	double r = 0;
	for(int j = 1; j <= n; j++){
		if((1.0*a[i][j]/100) * solve(i+1) > r){
			next = j;
		}
	}

	ans.push_back(next);

	vector<int> prox = reconstruct(i+1);

	for(int j : prox) ans.push_back(j);

	return ans;
}

int main(){
	
	scanf("%d", &n);

	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	vector<int> ans = reconstruct(1);
	for(int i : ans){
		if(i) printf("%d ", i);
	}
	printf("\n");
    
    return 0;

}