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

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

vector<int> g[N+1];
int dist[N+1];
bool seen[N+1];
unordered_set<pair<int,int>, pair_hash> used;
int height[N+1];
int n;

int bfs(int root){
    
    memset(dist, INF, sizeof(dist));
    memset(seen, 0, sizeof(seen));

    queue<int> fila;
// inicia o primeiro da fila (distancia 0) //
// Se eu quiser por mais de um 0 aqui eu posso e os nós
// tem valores relativos com o mais proximo //
    seen[root] = true;
    dist[root] = 0;
    fila.push(root);
// loop dos proximos na sequencia de profundidade//
    while(!fila.empty()){

        int atual = fila.front();
        fila.pop();
            
        for(int next : g[atual]){
            if(!seen[next]){
                seen[next] = true;
                dist[next] = dist[atual] + 1;
                fila.push(next);     
            }
        }
    }
    /* no fim do while loop o array de dist vai estar populado
    com dist[nodeIndex] = distanceFromRoot
    */

    dist[0] = -1;
    int mx = 0;
    for(int i = 1; i <= n; i++){
    	if(dist[mx] < dist[i]) mx = i;
    }

    return mx;
}


int dfs(int u, int p, int t){
	used.insert({p,u});
	used.insert({u,p});

	int r = 1;
	for(int v : g[u]){
		if(v != p){
			r *= dfs(v, u, t);
		}
	}

	if(!r or u == t){
		return 0;
	}

	used.erase({p,u});
	used.erase({u,p});

	return 1;
}

void dfs2(int u, int p, int h){

	height[u] = h;

	for(int v : g[u]){
		if(v != p){
			if(used.count({u, v})){
				dfs2(v, u, h);
			}
			else{
				dfs2(v, u, h+1);
			}
		}
	}
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int a = bfs(1);
	int b = bfs(a);

	dfs(a, 0, b);
	dfs2(a, 0, 0);

	int c = 0;
	height[0] = -1;
	for(int i = 1; i <= n; i++){
		if(i != a and i != b and height[c] < height[i]) c = i;
	}

	printf("%d\n", dist[b] + height[c]);
	printf("%d %d %d\n", a, b, c);

    return 0;

}