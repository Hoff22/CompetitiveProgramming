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

vector<int> g[N+1];
map<pair<int,int>, int> m;
pair<int,int> points[N+1];
int color[N+1];
int ct_tw = 0;
int ct_on = 0;

void dfs(int u, int c){
	color[u] = c;
	if(color[u] == 2) ct_tw++;
	if(color[u] == 1) ct_on++;

	int px = points[u].fi;
	int py = points[u].se;

	for(int dx = -5; dx <= 5; dx++){
		for(int dy = -5; dy <= 5; dy++){
			int nx, ny;
			nx = px+dx;
			ny = py+dy;

			if(dx == 0 and dy == 0) continue;
			if(abs(dx)*abs(dx) + abs(dy)*abs(dy) > 25) continue;

			if(m.count({nx,ny})){
				if(color[m[{nx,ny}]] != 0) continue;
				if(c == 1){
					dfs(m[{nx,ny}], 2);
				}
				if(c == 2){
					dfs(m[{nx,ny}], 1);
				}
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    scanf("%d", &n);


    for(int i = 1; i <= n; i++){
    	int u, v;
    	scanf("%d %d", &u, &v);
    	points[i] = {u,v};
    	m[points[i]] = i;
    }

    int ans = 0;
    for(int i = 1; i <= n i++){
    	ct_tw = 0;
		ct_on = 0;
    	if(color[i] == 0) dfs(i, 1);
    	ans += min(ct_on,ct_tw);
	}


    printf("%d\n", ans);


    return 0;

}