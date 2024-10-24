#include <bits/stdc++.h>

#define N 2000000
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

typedef long long ll;


// Pollard's Rho Alg
//
// Usa o algoritmo de deteccao de ciclo de Floyd
// com uma otimizacao na qual o gcd eh acumulado
// A fatoracao nao sai necessariamente ordenada
// O algoritmo rho encontra um fator de n,
// e funciona muito bem quando n possui um fator pequeno
//
// Complexidades (considerando mul constante):
// rho - esperado O(n^(1/4)) no pior caso
// fact - esperado menos que O(n^(1/4) log(n)) no pior caso

ll mul(ll a, ll b, ll m) {
	ll ret = a*b - ll((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

ll pow(ll x, ll y, ll m) {
	if (!y) return 1;
	ll ans = pow(mul(x, x, m), y/2, m);
	return y%2 ? mul(x, ans, m) : ans;
}

bool prime(ll n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;

	ll r = __builtin_ctzll(n - 1), d = n >> r;
	for (int a : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
		ll x = pow(a, d, n);
		if (x == 1 or x == n - 1 or a % n == 0) continue;
		
		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) break;
		}
		if (x != n - 1) return 0;
	}
	return 1;
}

ll rho(ll n) {
	if (n == 1 or prime(n)) return n;
	auto f = [n](ll x) {return mul(x, x, n) + 1;};

	ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
	while (t % 40 != 0 or gcd(prd, n) == 1) {
		if (x==y) x = ++x0, y = f(x);
		q = mul(prd, abs(x-y), n);
		if (q != 0) prd = q;
		x = f(x), y = f(f(y)), t++;
	}
	return gcd(prd, n);
}

vector<ll> fact(ll n) {
	if (n == 1) return {};
	if (prime(n)) return {n};
	ll d = rho(n);
	vector<ll> l = fact(d), r = fact(n / d);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

/* O(N^(1/4) * Log(N) + d(N) * Log(d(N))) such that d(N) is the number of divisors of N. */
vector<long long> divisors(long long n) {
    vector<ll> fs = fact(n);
   
    sort(fs.begin(),fs.end());
    
    vector<pair<ll,ll>> f;
   
    for(ll i : fs){
    	if(f.size() and f.back().fi == i) f.back().se++;
    	else f.push_back({i,1ll});
    }

    vector<long long> d = {1ll};

    // Building the divisors from the prime factors of n.
    for (int i = 0; i < f.size(); i++) {          // For every prime factor p.
        for (int j = d.size() - 1; j >= 0; j--) { // For every already existing divisor d.
            long long cur = d[j];

            for (int k = 1; k <= f[i].second; k++) { // Appending d * p^k.
                cur *= f[i].first;
                d.push_back(cur);
            }
        }
    }

    sort(d.begin(), d.end());

    return d;
}


void solve(){
	int n;
	cin >> n;
	vector<long long> a(n+1);

	map<ll, ll> freq;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		freq[a[i]]++;
	}

	long long ans = 0;

	for(auto i : freq){
		for(ll j : divisors(i.fi)){
			if(j * j > i.fi) break;
			if(i.fi % (j*j)) continue;
			
			if(j == 1){
				ans += 1ll * i.se * (i.se - 1) * (i.se - 2);
			}
			else{
				ans += 1ll * freq[i.fi / j] * i.se * freq[i.fi / (j*j)]; 
			}
		}
	}

	cout << ans << endl;
}

/*
  1 7 7 2 7
l 0 1 2 1 
r



*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}