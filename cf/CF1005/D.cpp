#include <bits/stdc++.h>

#define N 1000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* O(1) - Retrieves the index of the Most Significant Bit. */
long long msb_index(long long mask) {
    return 8ll * sizeof(mask) - __builtin_clzll(mask) - 1ll;
}

class SparseTable {
  private:
    vector<vector<long long>> table;
    vector<long long> a;

    /* O(1) - Retrieves ceil(log2(n)). */
    int floor_log2(int n) {
        assert(n > 0);
        return msb_index(n);
    }

    /* O(1) - Idempotent operation. f(f(x)) = f(x) or f(f(x, y), y) = f(x, f(x, y)) = f(x, y). */
    long long merge(long long x, long long y) {
        return max(x, y);
    }

  public:
    SparseTable() {}

    /* O(N * Log(N)). */
    SparseTable(vector<long long> const &v) {
        this->a = v;
        int k = floor_log2(v.size());

        // Allocating memory.
        table.resize(k + 1);

        for (int j = 0; j <= k; j++) {
            table[j].resize(a.size() - (1 << j) + 1);
        }

        // Base.
        for (int i = 0; i < a.size(); i++) {
            table[0][i] = a[i];
        }

        // Building for each 2^j <= n
        for (int j = 1; j <= k; j++) {
            // Building for each [i, i + 2^j - 1]
            for (int i = 0; i + (1 << j) - 1 < a.size(); i++) {
                table[j][i] = merge(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    /* O(1). */
    long long query(int l, int r) {
        // Finding greatest k such that 2^k <= r - l + 1
        int k = floor_log2(r - l + 1);
        return merge(table[k][l], table[k][r - ((1 << k) - 1)]);
    }
};
void solve(){
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	reverse(a.begin(), a.end());

	n++;
	a.push_back(INT_MAX);

	vector<ll> big_bit(n, 0), acc(n);

	acc[0] = a[0];
	big_bit[0] = msb_index(a[0]); 
	for(int i = 1; i < n; i++){
		acc[i] = acc[i-1] ^ a[i];
		big_bit[i] = msb_index(a[i]);
	}

	// for(int i = 0; i < n; i++) cout << a[i] << " ";
	// cout << endl;

	
	// for(int i = 0; i < n; i++) cout << acc[i] << " ";
	// cout << endl;


	// for(int i = 0; i < n; i++) cout << big_bit[i] << " ";
	// cout << endl;

	SparseTable bb(big_bit);

	for(int i = 0; i < q; i++){
		int x; cin >> x;

		int big_l = 0;
		int cur = x;

		while(big_l < n and cur){
			int l = big_l; int r = n;
			int ans = 0;

			// cout << big_l << ", " << cur << ": " << endl;

			while(l <= r){
				int m = (l + r) / 2;

				// cout << "  " << m << " " << bb[{big_l,m}] << endl;

				if(bb.query(big_l,m) < msb_index(cur)){
					l = m+1;
				}	
				else{
					ans = m;
					r = m-1;
				}
			}

			int t = x;
			if(ans > 0) t = x ^ acc[ans-1];

			// cout << "  " << t << " vs. " << a[ans] << endl;

			if(t >= a[ans]){
				big_l = ans + 1;
				cur = t ^ a[ans];
			}
			else{
				big_l = ans;
				break;
			}
		}

		cout << big_l << " ";
	}
	cout << endl;
}

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