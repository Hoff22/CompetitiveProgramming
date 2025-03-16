#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

multiset<int> merge(multiset<int>& nl, multiset<int>& nr){
	multiset<int> res = nr;
	res.insert(nl.begin(), nl.end());
	return res;
}

// O(log(N))
multiset<int> query(int l, int r, int i, int j) {
    multiset<int> nl, nr;
    int m = (l + r) / 2;

    if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
        return multiset<int>();
    }

    if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
    	// cout << (gl ? "x " : "y ") << l << " " << r << endl;
    	if(r-l+1 < 2) return multiset<int>();
    	return multiset<int>{(r-l+1)/2};
    }

    nl = query(l, m, i, j);
    nr = query(m + 1, r, i, j);

    return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

void solve(){
	int l[2], r[2];
	cin >> l[0] >> r[0] >> l[1] >> r[1];
	l[0] *= 2;
	r[0] *= 2;
	l[1] *= 2;
	r[1] *= 2;
	multiset<int> x = query(0, (1<<21), l[0], r[0]);
	multiset<int> y = query(0, (1<<21), l[1], r[1]);

	ll ans = 0;
	for(int i : x){
		for(int j : y){
			ans += max(i,j)/min(i,j);
		}
	}
	cout << ans << endl;
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