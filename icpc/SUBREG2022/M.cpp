#include <bits/stdc++.h>

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

constexpr int N = 100000;

typedef long long ll;

int mp[N + 1]; // mp[i] stores the minimum prime number which divides i. i is prime if it's not 0 and mp[i] == i.

/* O(N). */
vector<int> linear_sieve(int n) {
    vector<int> p; // Stores prime numbers.

    for (int i = 2; i <= n; i++) {
        if (!mp[i]) { // i is prime if we haven't found any smaller factors of it.
            mp[i] = i;
            p.push_back(i);
        }

        // Since every number x can be written as x = i * mp[x] we can iterate over every prime mp[x] (prime[j]).
        for (int j = 0; j < p.size() and p[j] <= mp[i] and i * p[j] <= n; j++) {
            mp[i * p[j]] = p[j];
        }
    }

    return p;
}

/* O(Log(N)). */
vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> f; // Sorted vector of pairs (prime, exponent).

    // Asserting that linear_sieve was executed before factorizing.
    assert(mp[2] == 2);

    // While there are still prime factors.
    while (n > 1) {
        if (!f.empty() and mp[n] == f.back().first) {
            f.back().second++;
        } else {
            f.push_back({mp[n], 1});
        }

        // Dividing n by its smallest prime factor.
        n /= mp[n];
    }

    return f;
}

/* O(d(N) * Log(d(N))) such that d(N) is the number of divisors of N. */
vector<int> divisors(int n) {
    vector<pair<int, int>> f = factor(n);
    vector<int> d = {1};

    // Building the divisors from the prime factors of n.
    for (int i = 0; i < f.size(); i++) {          // For every prime factor p.
        for (int j = d.size() - 1; j >= 0; j--) { // For every already existing divisor d.
            int cur = d[j];

            for (int k = 1; k <= f[i].second; k++) { // Appending d * p^k.
                cur *= f[i].first;
                d.push_back(cur);
            }
        }
    }

    sort(d.begin(), d.end());

    return d;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    vector<vector<pair<int,ll>>> sumP(N, vector<pair<int,ll>>());
    
    linear_sieve(N);

    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    for(int i = 1; i <= q; i++){
    	int x, v;
    	cin >> x >> v;
    	vector<pair<int,int>> prs =  factor(x);

    	for(auto j : prs){
    		int p = j.fi;
    		if(sumP[p].empty()){
    			sumP[p].push_back({i, v}); 
    		}
    		else{
    			sumP[p].push_back({i, sumP[p].back().se + v}); 
    		}
    	}
    }

    // for(int p = 2; p <= 6; p++){
	//     if(mp[p] != p) continue;
	//     cout << p << ": ";
	//     for(int i = 0; i < sumP[p].size(); i++){
	//     	cout << "(" << sumP[p][i].fi << "," <<  sumP[p][i].se << ") ";
	//     }
	//     cout << endl;
    // }

    for(int i = 1; i <= n; i++){
    	vector<pair<int,int>> prs =  factor(i);

    	int l = 1;
    	int r = q;
    	int ans = -1;

    	while(l <= r){
    		int m = (l+r)/2;

    		ll sum = 0;
    		set<int> seen;
    		int w = m;
    		for(auto j : prs){
	    		int p = j.fi;
	    		if(sumP[p].empty()) continue;
	    		int again = 1;

	    		while(again){
		    		int l2 = 0;
		    		int r2 = sumP[p].size()-1;
		    		int ans2 = -1;

		    		while(l2 <= r2){
		    			int m2 = (l2+r2)/2;

		    			if(sumP[p][m2].fi <= w){
		    				ans2 = m2;
		    				l2 = m2+1;
		    			}
		    			else{
		    				r2 = m2-1;
		    			}
		    		}

		    		if(seen.count(sumP[p][ans2].fi)){
		    			w--;
		    			continue;
		    		}
	    			again = 0;

		    		if(ans2 != -1){
		    			sum += sumP[p][ans2].se;
		    			seen.insert(sumP[p][ans2].fi);
		    		}
	    		}

	    	}

	    	// cout << "m: " << m << " | sum: " << sum << endl; 

	    	if(sum >= a[i]){
	    		ans = m;
	    		r = m-1;
	    	}
	    	else{
	    		l = m+1;
	    	}
    	}
    	cout << ans << endl;
    }



    return 0;

}