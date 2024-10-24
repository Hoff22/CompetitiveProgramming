#include <bits/stdc++.h>

#define N 400000
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

vector<int> ps;
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

vector<pair<int,int>> g[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> a(n+1);

	vector<int> pos(300001, -1);

	for(int i = 1; i <= n; i++){
		scanf(" %d", &a[i]);
	}

	int s, r;
	scanf(" %d %d", &s, &r);

	int k = n+1;
	for(int i = 1; i <= n; i++){
		vector<pair<int,int>> factors = factor(a[i]);

		for(auto p : factors){
			if(pos[p.fi] == -1) {
				pos[p.fi] = k;
				k++;
			}

			int cur_pi = pos[p.fi];

			g[cur_pi].push_back({i, 1});
			g[i].push_back({cur_pi, 0});
		}
	}

	vector<int> d(N+1, INF);
	vector<int> spt(N+1, 0);
	deque<int> q;
 
	d[s] = 0;
	q.push_front(s);
 
	while(!q.empty()){
 
		int u = q.front();
		q.pop_front();
 
		//printf("v : %d\n", u);
 
		for(auto e : g[u]){
			int v = e.fi;
			int w = e.se;
			//printf("\t%d %d\n", v, w);
			
			if(d[u] + w < d[v]){
				spt[v] = u;
				d[v] = d[u] + w;
				//printf("\t pushed %d\n", v);
				if(w){
					q.push_back(v);
				}
				else{
					q.push_front(v);
				}
			}
		}
	}

	if(d[r] == INF){
		printf("-1\n");
	}
	else{
		vector<int> path;

		int u = r;
		while(u != 0){
			if(u <= n) path.push_back(u);
			u = spt[u];
		}

		printf("%d\n", (int)path.size());
		reverse(path.begin(), path.end());
		for(int i : path){
			printf("%d ", i);
		}
		printf("\n");
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ps = linear_sieve(300000);
	
	solve();
    return 0;

}