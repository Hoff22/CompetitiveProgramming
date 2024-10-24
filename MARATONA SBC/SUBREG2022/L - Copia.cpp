#include <bits/stdc++.h>

#define N 100000
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


int color[N+1];
int sub_size[N+1];
int total_color[N+1];

map<pair<int,int>, int> edges;
vector<int> g[N+1];
int parent[N+1];

int root_tree(int u, int p){
	parent[u] = p;
	vector<int> ngu;
	for(int i : g[u]){
		if(p == i) continue;
		ngu.push_back(i);
		sub_size[u] += root_tree(i, u);
	}
	g[u] = ngu;
	return sub_size[u] + 1;
}

int solve(int u, int p){

	for(int v : g[u]){
		if(v == p) continue;

		solve(v, u);
	}

	

}


int n;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n; 

    for(int i = 0; i < n; i++){
    	cin >> color[i+1];
    	total_color[color[i+1]]++;
    }

    for(int i = 1; i < n; i++){
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	edges[{u,v}] = i;
    	edges[{v,u}] = i;
    }

    root_tree(1,0);

    vector<pair<map<int,int>, int>> cnt(n+1);
    vector<int> childs(n+1);
    vector<int> ans(n+1);
    queue<int> q;

    for(int i = 1; i <= n; i++){
    	if(g[i].size() == 0) {q.push(i);}
    	childs[i] = g[i].size();
    }

    while(!q.empty()){
    	int u = q.front();
    	q.pop();
    	if(u == 1) break;

    	int cur_e = edges[{u, parent[u]}];

    	if(sub_size[u] == 0){
    		cnt[u].fi[color[u]] = 1;
    		cnt[u].se = total_color[color[u]] - 1;
    		ans[edges[{u, parent[u]}]] = cnt[u].se;
    		childs[parent[u]]--;
    		if(childs[parent[u]] == 0) {q.push(parent[u]);}
    		continue;
    	}

    	int large_child = 1;
    	for(int v : g[u]){	
    		if(sub_size[v] > sub_size[large_child]) large_child = v;
    	}

    	if(g[u].size()){
    		swap(cnt[u], cnt[large_child]);
    	}

    	ans[cur_e] = cnt[u].se;
    	ans[cur_e] -= cnt[u].fi[color[u]];
    	cnt[u].fi[color[u]]++;
    	cnt[u].se += (total_color[color[u]] - cnt[u].fi[color[u]]);
    	ans[cur_e] += (total_color[color[u]] - cnt[u].fi[color[u]]);

    	for(int v : g[u]){	
    		if(v == large_child) continue;
    		for(auto c : cnt[v].fi){
    			//cnt[u].fi[c.fi] += c.se;

    			ans[cur_e] -= cnt[u].fi[c.fi] * c.se;
		    	cnt[u].fi[c.fi] += c.se;
		    	cnt[u].se += ((total_color[c.fi] - cnt[u].fi[c.fi]) * c.se);
		    	ans[cur_e] += ((total_color[c.fi] - cnt[u].fi[c.fi]) * c.se);
    		}
    	}

    	childs[parent[u]]--;
		if(childs[parent[u]] == 0) {q.push(parent[u]);}
    }

    for(int i = 1; i < n; i++){
    	cout << ans[i] << " ";
    }
    cout << endl;



    return 0;

}