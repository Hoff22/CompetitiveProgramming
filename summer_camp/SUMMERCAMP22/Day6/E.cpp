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

vector<int> g[N+1];
int a[N+1];
int n;

int solve(int u, int p, int l){
	if(l == 26){
		return 0;
	}

	a[u] = l;

	int r = 1;
	if(u == 1){
		for(int v : g[u]){
			if(v != p){
				r *= solve(v, u, l + 1);
			}
		}
	}
	else if(g[u].size() > 2){
		printf("%d %d\n", u, l);
		for(int v : g[u]){
			if(v != p){
				if(h%2){
					r *= solve(v, u, l + 2);
				}
				else{
					r *= solve(v, u, l + 1);
				}
			}
		}
	}
	else{
		for(int v : g[u]){
			if(v != p){
				r *= solve(v, u, l);
			}
		}
	}

	return r;
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	if(solve(1, 0, 0)){

		for(int i = 1; i <= n; i++){
			printf("%c ", 'A' + a[i]);
		}
		printf("\n");

	}
	else{
		printf("Impossible!\n");
	}

    return 0;

}