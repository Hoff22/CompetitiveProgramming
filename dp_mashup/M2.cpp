#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
 
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
#define printv(i,x) FOR(i, x.size()) cout << x[i] << " "; cout << "\n";
#define scanv(x,a) FOR(i,a) cin >> x[i];
#define onebasedscanv(x,a) FORI(i,1,a+1) cin >> x[i];
#define virgula(x) cout << fixed << setprecision(9) << x << "\n";
 
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
 
const int MOD = 1000000007;
const long long INF = 0x3f3f3f3f3f3f3f3f;

// For interactive problems: cout.flush();

#define MAX 5000

long long n,m,t;
vl edges[MAX+1];
vl costs[MAX+1];

int dp[MAX+1][MAX+1];

long long p(long long u, long long qntsvisited)
{
    // cout << u << " " << qntsvisited << "\n";
    // cout.flush();

    /* Se chegou aqui e o qntsvisited
    nao ta zerado, quer dizer que nao
    tem como visitar o total passado
    pra funcao inicialmente */
    if (u == n or qntsvisited <= 0)
    {
        if (u != n or qntsvisited > 0)
            return INF;
        else
            return 0;

        /* Se chegou aqui, quer dizer que
        visitamos o numero necessario de
        showplaces ou mais, entao acaba
        pq queremos saber o minimo custo
        necessario pra isso */
    }

    if (dp[u][qntsvisited] != -1)
        return dp[u][qntsvisited];

    long long mini = INF;
    FOR(i,sz(edges[u]))
    {
        long long v = edges[u][i];
        long long w = costs[u][i];

        mini = min(mini, p(v,qntsvisited-1) + w);
    }

    return dp[u][qntsvisited] = mini;
}

vl path;

void rec(long long u, long long qntsvisited)
{
    if (u == n or qntsvisited <= 0)
        return;

    long long mini = INF;
    long long escolhido = -1;
    FOR(i,sz(edges[u]))
    {
        long long v = edges[u][i];
        long long w = costs[u][i];

        if (p(v,qntsvisited-1)+w < mini)
        {
            mini = p(v,qntsvisited-1)+w;
            escolhido = i;
        }
    }

    path.pb(edges[u][escolhido]);
    rec(edges[u][escolhido], qntsvisited-1);
}

void solve()
{
    cin >> n >> m >> t;

    FOR(i,m)
    {
        long long u,v,w;
        cin >> u >> v >> w;

        edges[u].pb(v);
        costs[u].pb(w);
    }

    /* Tenta conseguir a maior quantidade
    de visitados que o custo seja menor ou
    igual a t */
    FORd(i,5000)
    {
        if (p(1,i) <= t)
        {
            path.pb(1);
            rec(1,i);
            cout << i+1 << "\n";
            printv(j,path);

            return;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    memset(dp,-1,sizeof(dp));
 
    int tt = 1;
    // cin >> tt;

    while (tt--)
    {
        solve();
        // cout << "\n----------\n";
    }
    return 0;
}