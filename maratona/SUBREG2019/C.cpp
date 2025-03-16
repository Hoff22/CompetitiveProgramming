#include <bits/stdc++.h>

#define N 20010
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    cin >> x >> y;


    long long h, v;
    cin >> h >> v;

    long long ans = 0;

    vector<pair<long long,long long>> hor;
    vector<pair<long long,long long>> ver;

    for(long long i = 0; i < h; i++){
        long long y1,y2;
        cin >> y1 >> y2;
        hor.push_back({y1,y2});
    }
    for(long long i = 0; i < v; i++){
        long long y1,y2;
        cin >> y1 >> y2;
        ver.push_back({y1,y2});
    }

    ordered_set s;
    sort(hor.begin(), hor.end());
    for(long long i = 0; i < hor.size(); i++){
        long long r = hor[i].se;
        ans += s.order_of_key(-r);
        s.insert(-r);
    }
    reverse(hor.begin(), hor.end());
    s.clear();
    for(long long i = 0; i < hor.size(); i++){
        long long r = hor[i].se;
        ans += s.order_of_key(r);
        s.insert(r);
    }


    s.clear();
    sort(ver.begin(), ver.end());
    for(long long i = 0; i < ver.size(); i++){
        long long r = ver[i].se;
        ans += s.order_of_key(-r);
        s.insert(-r);
    }
    reverse(ver.begin(), ver.end());
    s.clear();
    for(long long i = 0; i < ver.size(); i++){
        long long r = ver[i].se;
        ans += s.order_of_key(r);
        s.insert(r);
    }

    cout << ans/2 + ((h+1)*(v+1)) << endl;

    return 0;
}