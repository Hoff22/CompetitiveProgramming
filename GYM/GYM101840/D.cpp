#include <bits/stdc++.h>

#define N 100000
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

int parent[N];
int height[N];

// make_set(a) creates a new set/tree with only the node a
void make_set(int a){
	parent[a] = a;
	height[a] = 0;
}

// find(a) returns the answer to which set the element a belongs to
int find_set(int a){
	if(parent[a] == a){
		return a;
	}
	return parent[a] = find_set(parent[a]);
}

// union(a, b) merges two sets into one
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	
	if(a != b){
		if(height[b] > height[a]) swap(a, b); // bigger's always a;
		parent[b] = a;
		if(height[a] == height[b]) height[a] += 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	linear_sieve(100000);

	ifstream file("dream.in");

    int t;

    file >> t;

    for(int ts = 1; ts <= t; ts++){
    	int n;
    	file >> n;

    	vector<int> v(n);
    	//cout << ts << " " << n << endl;
    	for(int i = 0; i < n; i++) file >> v[i];

    	vector<vector<int>> has(100001, vector<int>());

    	for(int i = 0; i < n; i++){
    		make_set(i);
    		for(int d : divisors(v[i])){
    			has[d].push_back(i);
    		}
    	}

    	int count = 0;
    	long long ans = 0;
    	for(int d = 100000; d >= 1; d--){
    		while(count < n-1 and has[d].size() > 1){
    			int a = has[d][0];
    			int b = has[d].back();
                has[d].pop_back();

    			if(find_set(a) != find_set(b)){
    				ans += d;
    				count++;
    			}

    			union_set(a,b);

                has[d][0] = find_set(has[d][0]);
    		}
    		if(count == n-1) break;
    	}

    	cout << "Case " << ts << ": " << ans << endl;
    }
    return 0;

}