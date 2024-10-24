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

int n, m;
vector<int> p[N+1];

void solve(){
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++) p[i].clear();

	set<vector<int>> s;

	for(int i = 1; i <= n; i++){
		p[i].assign(m+1, 0);
		vector<int> ps(m+1);
		for(int j = 1; j <= m; j++){
			scanf("%d", &p[i][j]);
			ps[p[i][j]] = j;
		}

		vector<int> temp;
		for(int j = 1; j <= m; j++){
			temp.push_back(ps[j]);
			s.insert(temp);
		}
	}


	for(int i = 1; i <= n; i++){
		int k = 0;
		vector<int> temp;
		for(int j = 1; j <= m; j++){
			temp.push_back(p[i][j]);
			if(s.find(temp) != s.end()){
				k++;
			}
			else break;
		}

		printf("%d ", k);
	}
	printf("\n");
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}