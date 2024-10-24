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
 
#define MAX 10000000

/* O(N * Log(Log(N))). */
vector<ll> sieve(int n) {
    vector<int> lp(n+1,0);
    vector<ll> pr;

    for (int i=2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    return pr;
}

ll a,b,c,d;
vl primes;

ll p(int i, ll v, ll cnt)
{
    // cout << i << " " << v << " " << cnt << " " << r << "\n";

    if (i == sz(primes) or v*primes[i] > max(b,d))
    {
        // cout << "caso base: " << r/v << "*(" << 2*cnt-1 << ")\n";
        return (v != 1)*(2*cnt-1)*(b/v - (a-1)/v)*(d/v - (c-1)/v);
    }

    return p(i+1, v*primes[i], (cnt+1)%2) + p(i+1, v, cnt);
}

void solve()
{
    cin >> a >> b >> c >> d;

    // Check primes that belong to range (a,b) inclusive

    cout << (b-a+1)*(d-c+1) - p(0,1,0) << "\n";

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    // memset(dp,-1,sizeof(dp));

    // cout << fixed << setprecision(9);
 
    int tt = 1;
    // cin >> tt;

    primes = sieve(MAX);
    // cout << sz(primes) << "\n";

    while (tt--)
    {
        solve();
        // cout << "\n----------\n";
    }
    return 0;
}