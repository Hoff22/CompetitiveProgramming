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

long long x_map[N+1];
long long y_map[N+1];
vector<long long> x_sorted[N+1];
vector<long long> y_sorted[N+1];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    scanf("%d", &n);

    vector<pair<long long,long long>> p_x;
    vector<pair<long long,long long>> p_y;

    for(int i = 1; i <= n; i++){
        long long x, y;
        scanf("%lld %lld" , &x, &y);
        
        p_x.push_back({x,y});
        p_y.push_back({y,x});
    }

    sort(p_x.begin(), p_x.end());
    sort(p_y.begin(), p_y.end());

    int j = 0;
    for(int i = 0; i < p_x.size(); i++){
        if(p_x[i].fi != x_map[j]){
            j++;
        }
        x_map[j] = p_x[i].fi;

        x_sorted[j].push_back(p_x[i].se);
    }

    int mx_x = j;

    j = 0;
    for(int i = 0; i < p_x.size(); i++){
        if(p_y[i].fi != y_map[j]){
            j++;
        }
        y_map[j] = p_y[i].fi;

        y_sorted[j].push_back(p_y[i].se);
    }

    int mx_y = j;

    for(int i = 1; i <= n; i++){
        sort(x_sorted[i].begin(), x_sorted[i].end());
        sort(y_sorted[i].begin(), y_sorted[i].end());
    }

    // test x first

    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long px = p_x[i].fi;
        long long py = p_x[i].se;

        ans = max(ans, abs(px - x_map[1])    + abs(py - x_sorted[1][0]));
        ans = max(ans, abs(px - x_map[1])    + abs(py - x_sorted[1][x_sorted[1].size()-1]));
        ans = max(ans, abs(px - x_map[mx_x]) + abs(py - x_sorted[mx_x][0]));
        ans = max(ans, abs(px - x_map[mx_x]) + abs(py - x_sorted[mx_x][x_sorted[mx_x].size()-1]));

        ans = max(ans, abs(py - y_map[1])    + abs(px - y_sorted[1][0]));
        ans = max(ans, abs(py - y_map[1])    + abs(px - y_sorted[1][y_sorted[1].size()-1]));
        ans = max(ans, abs(py - y_map[mx_y]) + abs(px - y_sorted[mx_y][0]));
        ans = max(ans, abs(py - y_map[mx_y]) + abs(px - y_sorted[mx_y][y_sorted[mx_y].size()-1]));
    }

    printf("%lld\n", ans);

    return 0;

}