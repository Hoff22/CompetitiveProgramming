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

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a(n-1);

    for(int i = 1; i <= n; i++){
        g[i].clear();
    }
    for(int i = 0; i < n-1; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i< n;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[v].push_back(u);
        g[u].push_back(v);
    }

    set<pair<int,pair<int,int>>> s;

    for(int u = 1; u <= n; u++){
        for(int v : g[u]){
            s.insert({1,{u,v}});
        }
    }

    vector<int> ans;

    /*
        go in reverse order removing spaces left in white
        always maintain the shortest distance
        you're a smart guy you'll figure it out

    */

    for(int i = n-2; i >= 0; i--){
        int d = (*s.begin()).fi;
        //printf("%d %d %d\n",(*s.begin()).fi, (*s.begin()).se.fi,(*s.begin()).se.fi);
        ans.push_back(d);

        for(int u : g[a[i]]){
            s.erase({d, {a[i],u}});
            s.erase({d, {u,a[i]}});
            s.insert({d+1, {a[i],u}});
            s.insert({d+1, {u,a[i]}});
        }
    }

    for(int i = 0; i < ans.size(); i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}


/*

  1 0 0 1 0 0  = 2a
  0 1 0 0 1 0  = a
  1 1 0 1 1 0  = b


  1 1 0 1 1 0
  0 1 0 0 1 0
             = 100100

1 0 0 1 0 0 0


  1 0 0 1 0
  0 1 0 0 1 a 
  1 1 0 1 1 b


  1 1 0
    1 1  a


   1 0 1 
   0 1 0 a
   1 1 0 b






  1 0 0 1 0 0
    0 1 0 0 1



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