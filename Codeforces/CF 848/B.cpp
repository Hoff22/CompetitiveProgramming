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

void solve(){
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);

	vector<int> p(n+1);
	vector<int> pos(n+1);
	vector<int> a(m+1);

	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
	}

	int best = INF;
	for(int i = 1; i < m; i++){
		if(pos[a[i]] < pos[a[i+1]] and pos[a[i+1]] <= pos[a[i]] + d){
			int d1 = (pos[a[i+1]] - pos[a[i]]);
			int d2 = INF;

			int t = pos[a[i]] + d - pos[a[i+1]] + 1;

			if(pos[a[i]] + d < n){
				d2 = pos[a[i]] + d - pos[a[i+1]] + 1;
			}
			else if(pos[a[i]] - 1 >= t){
				d2 = pos[a[i]] + d - pos[a[i+1]] + 1;
			}
			else if((pos[a[i]] - 1) + (n - pos[a[i+1]]) >= t){
				d2 = pos[a[i]] + d - pos[a[i+1]] + 1;
			}

			best = min({d1,d2,best});
		}
		else{
			best = 0;
		}
	}

	printf("%d\n", best);

}

/*





*/

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