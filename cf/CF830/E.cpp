#include <bits/stdc++.h>
 
#define N 5000
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
 
/* O(sqrt(N)). */
vector<pair<long long, long long>> factor(long long n) {
    vector<pair<long long, long long>> f; // Sorted vector of pairs (prime, exponent).
 
    // For every prime p up to sqrt(n).
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            f.push_back({p, 0ll});
 
            // While p divides n, keep dividing n by p and increasing the number of p factors.
            while (n % p == 0) {
                n /= p;
                f.back().second++;
            }
        }
    }
 
    // If n is not 1 by now, then it is a prime factor.
    if (n > 1) {
        f.push_back({n, 1ll});
    }
 
    return f;
}
 
long long a, b, c, d;
vector<pair<long long, long long>> f;
 
pair<long long, long long> go(long long x, long long y, long long i){
 
	//printf("%lld %lld\n", x, y);
 
	if(i == f.size()){
 
		x = (c - (c % x));
		y = (d - (d % y));
 
		if(a < x and b < y){
			return {x, y};
		}
 
		return {-1, -1};
	}
 
	pair<long long, long long> r = {-1,-1};
	
	//printf("f: %lld - %lld\n", f[i].fi, f[i].se);
 
	vector<long long> ml(f[i].se+1);
	vector<long long> mr(f[i].se+1);
 
	ml[0] = 1;
	mr[f[i].se] = 1;
 
	for(int j = 1; j <= f[i].se; j++){
		ml[j] = ml[j-1] 		* f[i].fi;
		mr[f[i].se-j] = mr[f[i].se-j+1] * f[i].fi;
	}
 
 
	for(int j = 0; j <= f[i].se; j++){
		//printf("%lld - %lld\n", ml[j], mr[j]);
 
		r = max(
			r,
			go(x * ml[j], y * mr[j], i+1)
		);
 
	}
 
	return r;
}
 
void solve(){
 
    scanf("%lld %lld %lld %lld",&a, &b, &c, &d);
 
    vector<pair<long long, long long>> fa = factor(a);
    vector<pair<long long, long long>> fb = factor(b);

    for(int i = 0; i < fa.size(); i++){
    	for(int j = 0; j < fb.size(); j++){
    		if(fa[i].fi == fb[j].fi){
    			fa[i].se += fb[j].se;
    			fb[j].se = 0;
    		}

    	}
    }

    for(int j = 0; j < fb.size(); j++){
    	if(fb[j].se > 0){
    		fa.push_back(fb[j]);
    	}
    }

    f = fa;
 
    //printf("%d\n", f.size());
 
    pair<long long, long long> r = go(1,1,0);
 
	printf("%lld %lld\n", r.fi, r.se);
 
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