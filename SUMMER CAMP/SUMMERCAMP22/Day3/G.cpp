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

vector<int> g1[N+1];
vector<int> g2[N+1];


pair<int,int> bfs(int root, vector<int> g[N+1]){
    queue<int> fila;
	bool seen[N+1];
	int dist[N+1];

	memset(seen, 0, sizeof(seen));
	memset(dist, INF, sizeof(dist));
// inicia o primeiro da fila (distancia 0) //
// Se eu quiser por mais de um 0 aqui eu posso e os nós
// tem valores relativos com o mais proximo //
    seen[root] = true;
    dist[root] = 0;
    fila.push(root);
// loop dos proximos na sequencia de profundidade//

    int r = root;
    while(!fila.empty()){

        int atual = fila.front();
        fila.pop();
    	if(dist[r] <= dist[atual]){
    		r = atual;
    	}
            
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

    return {r,dist[r]};
}

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n-1 ; i++){
		int u , v;
		scanf("%d %d", &u, &v);
		
		g1[u].push_back(v);
		g1[v].push_back(u);
	}

	int m;
	scanf("%d", &m);

	for(int i = 0; i < m-1 ; i++){
		int u , v;
		scanf("%d %d", &u, &v);
		
		g2[u].push_back(v);
		g2[v].push_back(u);
	}

	int a = 0;
	for(int i = 1; i <= n; i++){
		if(g1[i].size() == 1){
			a = bfs(bfs(i, g1).fi, g1).se + 1;
			break;
		}
	}

	int b = 0;
	for(int i = 1; i <= m; i++){
		if(g2[i].size() == 1){
			b = bfs(bfs(i, g2).fi, g2).se + 1;
			break;
		}
	}

	//printf("%d %d\n", a, b);

	if((b+1)/2 >= a){
		printf("FF\n");
	}
	else{
		printf("GGEZ\n");
	}

    return 0;

}