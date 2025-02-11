#include <bits/stdc++.h>

#define N 300000
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

int a[N+1];
int b[N+1];

int dist[N+1];
int parent[N+1];
int n;

void bfs(int root){
	for(int i = 0; i <= n; i++) dist[i] = INF;
	memset(parent, -1, sizeof(parent));

	queue<int> q;

	dist[root] = 0;
	q.push(root);

	while(!q.empty()){

		int u = q.front();
		q.pop();

 		if(u == 0) break;

		for(int i = u; i >= u - a[u]; i--){
			int v;
			if(i > 0) v = i + b[i];
			else v = 0;

			//printf("%d, %d", u, v);

			if(dist[v] == INF){
				dist[v] = dist[u] + 1;
				q.push(v);
				parent[v] = max(0, i);
				parent[i] = u;
			}
		}

	}
}

vector<int> pP(int u){
	vector<int> r;
	if(parent[u] == -1){
		r.push_back(u);
		return r;
	}
	r = pP(parent[u]);

	r.push_back(u);
	return r;
}

int main(){
	
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}

	bfs(n);

	if(dist[0] == INF) printf("-1\n");
	else{
		printf("%d\n", dist[0]);
		vector<int> ans = pP(0);

		int j = 1;
		for(int i = 0; i < ans.size(); i++){
			if(i == 0) continue;
			if(b[ans[i]] == 0){
				printf("%d ", ans[i]);
				// j = -1;
			}
			else if(j == 1){
				printf("%d ", ans[i]);
				j *= -1;
			}
		}
		printf("\n");
		
	}

    return 0;

}