#include <bits/stdc++.h>

#define N 200000
#define T 10
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

typedef long long ll;

int parent[N+1];
int height[N+1];

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
int union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	
	if(a != b){
		if(height[b] > height[a]) swap(a, b); // bigger's always a;
		parent[b] = a;
		if(height[a] == height[b]) height[a] += 1;
	}
	return a;
}

void solve(){
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n+1,vector<int>(T+1, 0));
	vector<int> as(n+1,-1);

	int t = 0;

	for(int i = 0; i < m; i++){
		int ai, d, k;
		cin >> ai >> d >> k;
		int idx = d;
		
		// cout << ai << " " << d << " " << k << endl;
		
		int cur = t++;
		make_set(cur);

		for(int j = ai; j <= ai + k*d; j += d){
			int nj = j;
			if(a[j][idx]){
				nj = a[j][idx];
			}

			if(as[j] != -1) cur = union_set(as[j], cur);

			a[j][idx] = max(a[j][idx], ai + k*d);
			as[j] = cur;
			j = nj;
			// cout << " " << j << endl;
		}
	}

	long long ans = 0;

	for(int i = 1; i <= n; i++){
		if(as[i] == -1) ans++;		
	}

	set<int> comp;
	for(int i = 0; i < m; i++){
		if(parent[i] != -1) comp.insert(find_set(i));
	}

	cout << ans + comp.size() << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		solve();
	}
    return 0;

}