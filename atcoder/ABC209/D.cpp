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
#define LOG 21

using namespace std;

vector<int> g[N+1];

// parent[v] == node u that is a parent to v;
int parent[N+1];
// ancestor[v][j] == node u that is the 2^j-th ancestor to v;
int ancestor[N+1][LOG];
int n,q;

void build(){
	// initializes dp of all 0-th ancestors wich are the parents itself
	for(int v = 1; v <= n; v++){
		ancestor[v][0] = parent[v];
	}
	// fills all the 2^j-th ancestors using previous values
	// parent[v] < v must be true
	// parent[0] must be 0
	for(int v = 1; v <= n; v++){
		for(int j = 1; j < LOG; j++){
			ancestor[v][j] = ancestor[ ancestor[v][j-1] ][j-1];
		}
	}
}
// given v and k returns the k-th ancestor to v
int query(int v, int k){
	int ans = v;
	int a = 0;
	while(k){
		if(k & 1){
			ans = ancestor[ans][a];
		}
		a++;
		k >>= 1;
	}
	return ans;
}

int depth[N+1];
int it[N+1];
int ot[N+1];
int timer = 0;

void initParent(int u, int p, int d){
	parent[u] = p;
	depth[u] = d;

	it[u] = ++timer;

	for(int v : g[u]){
		if(v!=p)initParent(v,u,d+1);
	}

	ot[u] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return it[u] <= it[v] && ot[u] >= ot[v];
}

int main(){
	
	scanf("%d %d", &n, &q);

	for(int i = 0; i < n-1; i++){
		int u,v;
		scanf("%d%d", &u,&v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	initParent(1,0,0);
	build();

	for(int i = 0; i < q; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		int l = 1;
		if(it[a] > it[b]){

			int r = depth[a]; 
			int m;

			while(l < r){
				m = l + (r-l)/2;

				if(is_ancestor(query(a, m), b)){
					r = m;
				}
				else{
					l = m+1;
				}
			}		
		}
		else{
			int r = depth[b]; 
			int m;

			while(l < r){
				m = l + (r-l)/2;

				if(is_ancestor(query(b, m), a)){
					r = m;
				}
				else{
					l = m+1;
				}
			}
		}
		//printf("%d\n", l);
		if((depth[a]-depth[l] + depth[b]-depth[l]+1) % 2){
			printf("Town\n");
		}
		else{
			printf("Road\n");
		}

	}

    return 0;

}