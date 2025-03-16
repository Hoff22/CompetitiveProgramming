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
map<vector<int>, int> hs;
int cnt = 0;
int hs_1;

void root_tree1(int u, int p){
	vector<int> ngu;
	for(int i : g1[u]){
		if(p == i) continue;
		ngu.push_back(i);
		root_tree1(i, u);
	}
	g1[u] = ngu;
}
void root_tree2(int u, int p){
	vector<int> ngu;
	for(int i : g2[u]){
		if(p == i) continue;
		ngu.push_back(i);
		root_tree2(i, u);
	}
	g2[u] = ngu;
}

int hash1(int u){
	vector<int> p;

	for(int v : g2[u]){
		p.push_back(hash1(v)); 
	}

	if(!hs.count(p)) hs[p] = ++cnt;

	return hs[p];
}

int hash2(int u, int depth){
	vector<int> p;

	if(depth){
		for(int v : g1[u]){
			p.push_back(hash2(v,depth-1)); 
		}
	}

	if(!hs.count(p)) hs[p] = ++cnt;

	return hs[p];
}

int find(int u){

	for(int i = 0; i <= 100; i++){
		if(hash2(u, i) == hs_1){
			return 1;
		}
	}

	for(int v : g1[u]){
		if(find(v)) return 1;	
	}

	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	g1[u].push_back(v);
    	g1[v].push_back(u);
    }

    cin >> n;

    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	g2[u].push_back(v);
    	g2[v].push_back(u);
    }

    root_tree1(1,0);
    root_tree2(1,0);

    hs_1 = hash1(1);

    if(find(1)){
    	cout << "Y\n";
    }
    else{
    	cout << "N\n";
    }

    return 0;

}