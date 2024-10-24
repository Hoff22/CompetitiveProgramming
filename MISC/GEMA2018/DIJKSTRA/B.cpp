#include <bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f
#define FROM_A 0
#define FROM_B 1

using namespace std;

struct Edge{
	int u, v, w;

	Edge(){}

	Edge(int u_, int v_, int w_){
		this->u = u_;
		this->v = v_;
		this->w = w_;
	}
};

struct State{
	int u;
	int dist;

	State(){}

	State(int u_, int dist_){
		this->u = u_;
		this->dist = dist_;
	}

	bool operator < (const State &b) const{
		return dist > b.dist;
	}
};

vector<pair<int, int>> g[N+1];
bool inPath[N+1];
int dist[2][N+1];
Edge edges[N+1];

void dijkstra(int from, int root){
	priority_queue<State> pq;

	memset(inPath, 0, sizeof(inPath));

	dist[from][root] = 0;

	pq.push(State(root, dist[from][root]));

	while(!pq.empty()){
		int u = pq.top().u;
		pq.pop();

		if(!inPath[u]){

			inPath[u] = true;

			for(int i = 0 ; i < g[u].size(); i++){
				int v = g[u][i].first;
				int w = g[u][i].second;

				if(!inPath[v] and dist[from][u] + w < dist[from][v]){
					dist[from][v] = dist[from][u] + w;
					pq.push(State(v, dist[from][v]));
				}
			}
		}
	}
}

int main(){

	int n, m, a, b;

	scanf("%d%d%d%d", &n, &m, &a, &b);

	for(int i = 1; i <= m; i++){
		int u, v, w;

		scanf("%d%d%d", &u, &v, &w);

		g[u].push_back({v, w});
		g[v].push_back({u, w});
		edges[i] = Edge(u, v, w);
	}

	// inicializando os valores de distnacia aqui
	// pq se incializar na funcao vai apagar os valores
	// salvos de FROM_A
	memset(dist, INF, sizeof(dist));

	dijkstra(FROM_A, a);
	dijkstra(FROM_B, b);

	for(int i = 1; i <= m; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;

		if(dist[FROM_A][u] + w + dist[FROM_B][v] == dist[FROM_A][b] or dist[FROM_A][v] + w + dist[FROM_B][u] == dist[FROM_A][b]){
			printf("sim\n");
		}
		else{
			printf("nao\n");
		}
	}


	return 0;
}