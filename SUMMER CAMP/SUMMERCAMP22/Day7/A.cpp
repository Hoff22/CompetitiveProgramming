#include <bits/stdc++.h>

#define N 200000
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
struct hash_str{
	vector<long long> h; // hash of prefixes
	vector<long long> p; // powers of r (random value) for range querys of hash

	/* O(N) */
	hash_str(string s) : h(s.size()), p(s.size()){
		int n = s.size();
		h[0] = s[0];
		for(int i = 1; i < n; i++){
			h[i] = (h[i-1] * d + s[i]) % MOD;
		}

		p[0] = 1;
		for(int i = 1; i < n; i++){
			p[i] = (p[i-1] * d) % MOD;
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
int n, m;
string str;

pair<int,int> lcsub(hash_str a, string b, int of){
	int l, r;

	l = 1;
	r = min(n, (int)b.size());

	hash_str hb(b);

	int ans1 = 0;
	int ans2 = 0;
	while(l <= r){
		int md = (l + r) / 2;
		//cout << b << " " << l << " " << r << " " << md << endl;
		unordered_set<long long> h;
		for(int i = 0; i+md-1 < b.size(); i++){
			h.insert(hb.sub_hash(i, i+md-1));
		}

		int found = 0;
		int j = -1;
		for(int i = 0; i+md-1 < n; i++){
			//cout << of+i << " ";
			if(h.count(a.sub_hash(of+i, of+i+md-1))){
				//cout << "found: " << str.substr(of+i, of+md) << endl;
				found = 1;
				j = i;
			}
		}

		//cout << endl;

		if(found){
			if(ans1 <= md){
				ans1 = md;
				ans2 = j;
			}
			l = md + 1;
		}
		else{
			r = md - 1;
		}
	}

	//cout << ans2 << endl;
	return {ans1, ans2};
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	cin >> n >> m;
	cin >> str;

	hash_str ha(str+str);

	pair<int,int> best = {0,0};
	for(int i = 1; i <= m; i++){
		cin >> st[i];

		pair<int,int> cur = lcsub(ha, st[i], 0);

		if(cur.fi >= best.fi){
			best = cur;
		}
		//cout << st[i] << " " << cur.fi << " " << best.fi << endl;
	}

	//cout << best.fi << " " << best.se << endl;

	int ans1 = best.fi;
	int ans2 = 0;
	//cout <<"corte: " << best.se<<" " << ((best.fi + 1) / 2)<< endl;
	for(int i = 1 ; i <= m; i++){
		pair<int,int> cur1 = lcsub(ha, st[i], best.se + ((best.fi + 1) / 2));

		//cout << st[i] << " " << cur1.fi << " " << cur1.se << endl;
		
		ans2 = max(ans2, cur1.fi);
	}

	//cout<< ans1 << endl << ans2 << endl;
	cout << min(ans1,ans2) << endl;

    return 0;

}