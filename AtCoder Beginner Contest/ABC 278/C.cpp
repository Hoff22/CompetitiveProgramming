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

map<int,set<int>> g;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;

	cin >> n >> q;

	for(int i = 0; i < q; i++){

		int t, a, b;
		cin >> t >> a >> b;

		if(t == 1){
			g[a].insert(b);
		}
		else if(t == 2){
			g[a].erase(b);
		}
		else{
			if(g[a].count(b) and g[b].count(a)){
				cout << "Yes\n";
			}
			else cout << "No\n";
		}

	}
	

	return 0;

}