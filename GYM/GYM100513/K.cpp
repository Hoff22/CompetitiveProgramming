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

int parent[N];
int height[N];

// make_set(a) creates a new set/tree with only the node a
void make_set(int a){
	parent[a] = a;
	height[a] = 0;
}

// find(a) returns the answer to which set the element a belongs to
int find_set(int a){
	if(parent[a] == a){
		return a;
	}
	return parent[a] = find_set(parent[a]);
}

// union(a, b) merges two sets into one
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	
	if(a != b){
		if(height[b] > height[a]) swap(a, b); // bigger's always a;
		parent[b] = a;
		if(height[a] == height[b]) height[a] += 1;
	}
}

void solve(){
	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n,0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
		make_set(a[i][0]);
	}

	vector<pair<int,int>> edges;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(find_set(a[i][0]) != find_set(a[i][j])){
				int vidx = a[i][j]-1;

				for(int k = 0; k < n; k++){
					if(find_set(a[vidx][k]) == find_set(a[i][0])){
						edges.push_back({a[vidx][k], a[i][j]});
						union_set(a[vidx][k], a[i][j]);
						break;
					}
				}
			}
		}
	}

	for(auto e : edges){
		cout << e.fi << " " << e.se << endl;
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}