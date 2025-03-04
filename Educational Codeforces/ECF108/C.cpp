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
	vector<long long> u(n+1,0);
	vector<vector<long long>> unis(n+1);
	vector<long long> ans(n+1, 0);

	for(int i = 1; i <= n; i++) scanf("%lld", &u[i]);
	for(int i = 1; i <= n; i++) unis[i].push_back(0);
	for(int i = 1; i <= n; i++){
		long long s;
		scanf("%lld", &s);
		
		unis[u[i]].push_back(s);
	} 

	for(int i = 1; i <= n; i++){
		sort(unis[i].begin()+1, unis[i].end());
		reverse(unis[i].begin()+1, unis[i].end());
		for(int j = 1; j < unis[i].size(); j++){
			unis[i][j] += unis[i][j-1];
		}
		for(int j = 1; j < unis[i].size(); j++){
			ans[j] += unis[i][((unis[i].size()-1)/j)*j];
		}

		// if can for that k then value is unis[i][(unis[i].size()/k)*k];
		// can for that k if only if : 
	}
	
	for(int i = 1; i <= n; i++){
		printf("%lld ", ans[i]);
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}