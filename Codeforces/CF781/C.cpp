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
 
 
bool comp(vector<int> a, vector<int> b){
	return a.size() > b.size();
}
vector<int> vert[N+1];
 
 
void solve(){
	vector<vector<int>> hor;
 
	int timer[N+1];
 
	int n;
	scanf("%d", &n);
 
	for(int i = 1; i <= n; i++) vert[i].clear();

 	for(int v = 2; v <= n; v++){
		int u;
		scanf("%d", &u);
 
		vert[u].push_back(v);
	}
 
	int j = 0;
	for(int u = 1; u <= n; u++){
		if(vert[u].size()){
			vector<int> a;
			hor.push_back(a);
 
			for(int v : vert[u]){
				hor[j].push_back(v);
			}
			j++;
		}
	}
 
	vector<int> a;
	a.push_back(1);
	hor.push_back(a);
 
	sort(hor.begin(), hor.end(), comp);
 
	int t = 1;
	for(vector<int> h : hor){
		for(int v : h){
			timer[v] = t;
		}
		t++;
	}
	//reverse(hor.begin(), hor.end());
 
	for(vector<int> h : hor){
		for(int i = 1; i < h.size(); i++){
			if(timer[h[i-1]] + 1 > t){
				timer[h[i]] = t;
				t++;
			}
			else{
				timer[h[i]] = timer[h[i-1]] + 1;
			}
		}
	}
 
	// for(vector<int> h : hor){
	// 	for(int i = 0; i < h.size(); i++){
	// 		printf("%d ", timer[h[i]]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
 
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, timer[i]);
	}
 
	printf("%d\n", ans);
}
 
int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;
 
}