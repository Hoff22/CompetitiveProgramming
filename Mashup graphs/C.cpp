#include <bits/stdc++.h>

#define N 500000
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

int parent[N+1];
int set_size[N+1];

void make_set(int u){
	if(parent[u] != 0) return;
	parent[u] = u;
	set_size[u] = 1;
}

int find_set(int u){
	if(parent[u] == u) return u;
	return parent[u] = find_set(parent[u]);
}

void union_set(int u, int v){
	u = find_set(u);
	v = find_set(v);
	if(u == v) return;
	if(set_size[u] < set_size[v]) swap(u,v);
	parent[find_set(v)] = find_set(u);
	set_size[u] += set_size[v];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) make_set(i);

	for(int i = 1; i <= m; i++){
		int k;
		cin >> k;
		vector<int> ps;
		for(int j = 0; j < k; j++){
			int p;
			cin >> p;
			ps.push_back(p);
		}

		for(int j = 1; j < k; j++){
			union_set(ps[0], ps[j]);
		}

	}

	for(int i = 1; i <= n; i++){
		cout << set_size[find_set(i)] << " ";
	}
	cout << endl;

    return 0;

}