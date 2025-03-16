#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define OF 1000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

vector<int> g[N+1];
int n;

double solve(int u, int parent, int l){

	if(g[u].size() == 1 and u != 1){
		return l;
	}

	double p = 1;
	if(u == 1){
		p /= g[u].size();
	}
	else{
		p /= (g[u].size() - 1);
	}

	double ans = 0;
	for(int v : g[u]){
		if(v != parent){
			ans += p * solve(v, u, l + 1);
		}
	}

	return ans;	
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	//printf("%lf\n", solve(1, 0, 0));

	printf("%.16lf\n", 1.0 * solve(1, 0, 0));

    return 0;

}