#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i,a) for (int i=0; i<(a); i++)
#define FORI(i,a,b) for (int i=a; i<(b); i++)
#define FORd(i,a) for (int i=(a)-1; i>=0; i--)
#define FORId(i,a,b) for (int i=(a)-1; i>=(b); i--)
#define trav(a,x) for (auto& a : x)
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng)
#define printv(i,x) trav(i,x) cout << i << " "; cout << "\n";
 
#define sz(x) (int) (x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)
 
const int MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

#define MAX 200000

void solve()
{
    vpi a(3);
    FOR(i,3)
    {
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(all(a));

    int sum = 0;
    vector<vi> ans;

    FOR(i,a[0].f)
    {
        if (a[1].s == 0)
        {
            ans.pb({0,0,i});
        }
        else if (a[1].s == 1)
        {
            ans.pb({0,i,0});
        }
        else
        {
            ans.pb({i,0,0});
        }
    }
    sum += a[0].f;

    FOR(i,a[1].f-1)
    {
        if (a[0].s == 0)
        {
            ans.pb({0,0,i+1});
        }
        else if (a[0].s == 1)
        {
            ans.pb({0,i+1,0});
        }
        else
        {
            ans.pb({i+1,0,0});
        }
    }
    sum += a[1].f-1;

    // cout << sum << "\n";
    // FOR(i,sz(ans))
    // {
    //     FOR(j,3)
    //         cout << ans[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    int cur = a[0].f-1, curmove = 1;
    FOR(i,a[2].f)
    {
        if (sum <= a[2].f)
            break;

        if (cur == -1)
        {
            cout << "-1\n";
            return;
        }

        // Anda um
        ans.pop_back();
        if (a[2].s == 0)
        {
            ans[cur][2]+=curmove;
        }
        else if (a[2].s == 1)
        {
            ans[cur][1]+=curmove;
        }
        else
        {
            ans[cur][0]+=curmove;
        }

        // cout << "cur ans:\n";
        // FOR(j,sz(ans))
        // {
        //     FOR(k,3)
        //         cout << ans[j][k] << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
        // cout.flush();

        sum--;
        cur--;
        curmove++;
    }

    int curt = 1, curs = 1;
    while (true)
    {
        if (sum == a[2].f)
            break;

        if (curt > a[1].f)
        {
            curt = 1;
            curs++;
        }

        if (curs > a[0].f)
        {
            cout << "-1\n";
            return;
        }

        if (a[2].s == 0)
        {
            if (a[0].s == 1)
                ans.pb({curs,curt,0});
            else
                ans.pb({curt,curs,0});       
        }
        else if (a[2].s == 1)
        {
            if (a[0].s == 0)
                ans.pb({curs,0,curt});
            else
                ans.pb({curt,0,curs}); 
        }
        else
        {
            if (a[0].s == 0)
                ans.pb({0,curt,curs});
            else
                ans.pb({0,curs,curt});
        }

        curt++;
        sum++;
    }

    // Teste
    vector<set<pi>> seen(3);
    FOR(i,sz(ans))
    {
        if (seen[0].count({ans[i][0],ans[i][1]}) == 0)
        {
            seen[0].insert({ans[i][0],ans[i][1]});
        }
        if (seen[1].count({ans[i][0],ans[i][2]}) == 0)
        {
            seen[1].insert({ans[i][0],ans[i][2]});
        }
        if (seen[2].count({ans[i][1],ans[i][2]}) == 0)
        {
            seen[2].insert({ans[i][1],ans[i][2]});
        }
    }

    cout << sz(ans) << "\n";
    FOR(i,sz(ans))
    {
        FOR(j,3)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    FOR(i,3)
    {
        if (sz(seen[a[i].s]) != a[i].f)
        {
            cout << "nao: " << a[i].s << " ";
            cout << a[i].f << " != " << sz(seen[a[i].s]) << "\n";
            return;
        }
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    // memset(dp, -1, sizeof(dp));
 
    int tt = 1;
    // cin >> tt;

    while (tt--)
    {
        solve();
        // cout << "\n----------\n";
    }
    return 0;
}