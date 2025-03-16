#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

constexpr long long MOD = 998244353;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
const int d = uniform_int_distribution<int>(0, MOD-1)(rng);
long long p[N+1]; // powers of r (random value) for range querys of hash
struct hash_str{
	vector<long long> h; // hash of prefixes

	/* O(N) */
	hash_str(string s) : h(s.size()), p(s.size()){
		int n = s.size();
		h[0] = s[0];
		for(int i = 1; i < n; i++){
			h[i] = (h[i-1] * d + s[i]) % MOD;
		}
	}

	/* O(1) */
	long long sub_hash(int l, int r){
		if(l == 0){
			return h[r];
		}
		long long ans = (h[r] - h[l-1] * p[r-l+1]) % MOD;
		ans += MOD;
		ans %= MOD;

		return ans;
	}
};

string st[N+1];
string st[N+1];
int n, m;

pair<int,int> lcsub(hash_str a, hash_str b, int k){
	int l, r;

	l = 1;
	r = min(n, (int)b.size());

	pair<int,int> ans = {0,0};

	while(l <= r){
		int md = (l + r) / 2;
		cout << b << " " << l << " " << r << " " << md << endl;
		unordered_set<long long> h;
		for(int i = 0; i+md-1 < n; i++){
			h.insert(a.sub_hash(i, i+md-1));
		}

		int found = 0;
		int aux = 0;
		for(int i = 0; i+md-1 < st[k].size(); i++){
			if(h.count(b.sub_hash(i, i+md-1))){
				found = 1;
				aux = i;
				cout << st[k].substr(i, i+md-1) << endl;
			}
		}

		if(found){
			if(ans.se-ans.fi <= md){
				ans.fi = i;
				ans.se = i+md-1;
			}
			l = md + 1;
		}
		else{
			r = md - 1;
		}
	}

	return ans;
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p[0] = 1;
	for(int i = 1; i <= N; i++){
		p[i] = (p[i-1] * d) % MOD;
	}

	string a;

	cin >> n >> m;
	cin >> a;

	hash_str ha(a);

	int mx1 = 0;
	for(int i = 1; i <= m; i++){
		cin >> st[i];

		hash_str hb(st[i]);

		pair<int,int> cur = lcsub(ha, hb, i);

		int s = cur.se - cur.fi;

		pair<int,int> rotated = lcsub((ha - ha.sub_hash(cur.fi + s/2, n-1)) / p[n-1 - cur.fi + s/2 + 1])

		if(cur >= mx1){
			mx1 = cur;
		} 
	}

	for(int i = 1; i <= m; i++){
		int cur = lcsub(ha, st[i]);

		if(cur >= mx1){
			mx1 = cur;
		} 
	}

    return 0;

}