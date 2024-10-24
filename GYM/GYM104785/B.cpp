#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> ans(m+1, 0);

	vector<int> ent(m+1, 0);

	for(int i = 0; i < k; i++){
		int p, c;
		cin >> p >> c;

		if(ent[c] == 0) ent[c] = p;
		else{
			if(ent[c] == p){
				ans[c] += 100;
			}
			else{
				ans[c] += abs(ent[c]-p);
			}
			ent[c] = 0;
		}
	}

	for(int i = 1; i <= m; i++){
		if(ent[i]) ans[i] += 100;
	}

	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}