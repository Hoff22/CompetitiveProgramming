#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
 
constexpr int N = (1<<16);
constexpr int M = 200000;
 
set<pair<int,int>> g[N+1];
vector<int> ans;
 
void solve(){
	int k; 
	cin >> k;
 
	vector<int> deg(n+1,0);
 
	for(int i = 0; i < (1<<k); i++){
		int mask = (1<<k)-1;

		int z = (i<<1) & mask;
		int o = ((1<<1) & mask) | 1;

		if(z != i and !has.count({i,z})){
			deg[z]++;
			deg[i]++;
			g[i].push_nack({z,0});
			g[z].push_nack({i,0});
		} 		
		if(o != i and !has.count({i,o})){
			deg[o]++;
			deg[i]++;
			g[i].push_nack({o,1});
			g[o].push_nack({i,1});
		} 		
	}
 
	stack<int> st; st.push(0);
 
	while(st.size()){
		int u = st.top();
		if(deg[u] == 0){
			
		}
		else{
			for(int [i,d] : g[u]){

			}
		}
	}
 
	for(int i : ans) cout << i << " ";
	cout << endl;
}
 
int main(){
 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1;
 
	while(t--){
		solve();
	}
 
	return 0;
}