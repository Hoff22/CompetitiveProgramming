#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

// mandar +20 pra betina

void solve(){
	int n, m;
	cin >> n >> m;

	set<pair<int,int>> s;
	auto cmp = [](pair<int,int> a, pair<int,int> b) {
		if((a.fi-a.se) == (b.fi-b.se)) return a.fi < b.fi;
		return (a.fi-a.se) > (b.fi-b.se);
	};
	set<pair<int,int>, decltype(cmp)> len;

	s.insert({n,0});
	len.insert({n,0});

	for(int i = 0; i < m; i++){
		int x; cin >> x;
		auto j = s.lower_bound(make_pair(x,x));

		pair<int,int> big = {j->se, j->fi};


		s.erase({big.se, big.fi});
		len.erase({big.se, big.fi});

		s.insert({big.se, x});
		s.insert({x, big.fi});

		len.insert({big.se, x});
		len.insert({x, big.fi});
		

		cout << (len.begin()->fi - len.begin()->se) << " ";
	}

	cout << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;

}