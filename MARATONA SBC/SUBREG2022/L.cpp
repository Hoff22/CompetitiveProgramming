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

vector<map<int,int>> cnt;
vector<int> ans;

map<pair<int,int>, int> edges;
vector<int> g[N+1];

int solve(int u, int p){

	int large_child = 0;
	for(int v : g[u]){
		if(v == p) continue;
		sub_size[u] += solve(v, u);
		if(large_child == 0 or sub_size[v] > sub_size[large_child]) large_child = v;
	}

	int cur_e = edges[{u, p}];
	
	if(large_child){
		swap(cnt[u], cnt[large_child]);
	}
	else{
		cnt[u][color[u]] = 1;
		ans[cur_e] = total_color[color[u]] - 1;
		return sub_size[u]+1;
	}

	// cout << u << endl;
	ans[cur_e] = ans[edges[{u,large_child}]];
	// cout << "\t" << "ans[" << u << "," << p << "] = " << ans[cur_e] << endl;
	ans[cur_e] -= cnt[u][color[u]];
	// cout << "\t" << "ans[" << u << "," << p << "] = " << ans[cur_e] << endl;
	cnt[u][color[u]]++;
	ans[cur_e] += (total_color[color[u]] - cnt[u][color[u]]);
	// cout << "\t" << "ans[" << u << "," << p << "] = " << ans[cur_e] << endl;

	for(int v : g[u]){	
		if(v == large_child) continue;
		if(v == p) continue;
		for(auto c : cnt[v]){
			//cnt[u][c.fi] += c.se;

			ans[cur_e] -= cnt[u][c.fi] * c.se;
			// cout << "\t" << "ans[" << u << "," << p << "] = " << ans[cur_e] << endl;
	    	cnt[u][c.fi] += c.se;
	    	ans[cur_e] += ((total_color[c.fi] - cnt[u][c.fi]) * c.se);
			// cout << "\t" << "ans[" << u << "," << p << "] = " << ans[cur_e] << endl;
		}
	}
	return sub_size[u]+1;
}


int n;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n; 

    cnt.assign(n+1, map<int,int>());
    ans.assign(n+1, 0);

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

    solve(1, 0);
   
    for(int i = 1; i < n; i++){
    	cout << ans[i] << " ";
    }
    cout << endl;



    return 0;

}