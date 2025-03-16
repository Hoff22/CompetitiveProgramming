#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

/* ordered_set<int> s - Declaration
   s.order_of_key(x) - Returns the number of elements lesser than x in s. If x is in s then this corresponds to its 0-based index k.
   s.find_by_order(k) - Returns the k-th element in s. Use k such that 0 <= k < s.size(). */
template <class TKey, class TValue>
using ordered_map = __gnu_pbds::tree<TKey, TValue, less<TKey>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class TKey>
using ordered_set = ordered_map<TKey, __gnu_pbds::null_type>;

#define N 200000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;


// O(log_2(N))
long long fast_pow(long long a, long long b, long long mod){
    long long res = 1;
    while(b){
        if(b&1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod; 
}

// // find(a) returns the answer to which set the element a belongs to
// int find_set(int a){
// 	if(parent[a] == -1){
// 		return a;
// 	}
// 	return parent[a] = find_set(parent[a]);
// }

// // union(a, b) merges two sets into one
// void union_set(int a, int b){
// 	a = find_set(a);
// 	b = find_set(b);
	
// 	if(a != b){
// 		if(height[b] > height[a]) swap(a, b); // bigger's always a;
// 		parent[b] = a;
// 		if(height[a] == height[b]) height[a] += 1;
// 	}
// }

void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1), c(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}

	vector<int> parent(n+1,-1), sz(n+1,0);

	function<int(int)> find_set = [&](int x){
		return (parent[x] == -1 ? x : (parent[x] = find_set(parent[x])) ); 
	};
	auto union_set = [&](int x, int y){
		x = find_set(x), y = find_set(y);
		if(x!=y){
			if(sz[x]<sz[y]) swap(x,y);
			parent[y] = parent[x];
			sz[x] += sz[y];
		}
	};

	ll ans = 1;

	stack<int> st;

	for(int i = 1; i <= n; i++){
		int cnt = 0;
		if(st.empty()) st.push(i);
		else while(st.size() and a[st.top()] < a[i]){
			if(c[st.top()] == c[i]){
				cnt += 
			}
		}
	}
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