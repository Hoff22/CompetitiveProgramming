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
int distAN[N+1];
int distNA[N+1];

void bfs(int root, int (&dist)[N+1]){
    queue<int> fila;
	bool seen[N+1];

	memset(dist, 0, sizeof(dist));
	memset(seen, 0, sizeof(seen));
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
}

bool seen[N+1];
int paths[N+1];
int n, m;
long long dfs(int u){
	if(u == n) return 1;

	seen[u] = true;
	//printf("%d\n", u);

	long long r = 0;
	for(int v : g[u]){
		if(seen[v]){
			if(distAN[u] + distNA[v] + 1 == distAN[n]){
				r += paths[v];
			}
		}
		else{
			if(distAN[u] + distNA[v] + 1 == distAN[n]){
				r += dfs(v);
			}
		}
		r %= MOD;
	}

	paths[u] = r;

	return r;
}

int main(){
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int u,v;

		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	bfs(1, distAN);
	bfs(n, distNA);

	//printf("%d %d\n", distAN[n], distNA[1]);

	memset(seen, 0, sizeof(seen));
	printf("%lld\n", dfs(1));


    return 0;

}