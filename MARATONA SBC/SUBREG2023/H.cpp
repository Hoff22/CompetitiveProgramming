#include <bits/stdc++.h>

using namespace std;

#define N 1000000

typedef long long ll;

ll n, k;
ll cur[N+1];
ll ls[N+1];

struct state{
	int i;
	bool operator<(state other) const {
		if((cur[i]-ls[i]*k) == cur[other.i]-ls[other.i]*k){
			return i < other.i;
		}
		return (cur[i]-ls[i]*k) > cur[other.i]-ls[other.i]*k;
	}
};

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	vector<ll> c(n+1);

	vector<pair<ll,int>> e;

	for(int i = 1; i <= n; i++){
		ll l, r, c_;
		cin >> l >> r >> c_;

		ls[i] = l;

		e.push_back({l,-i});
		e.push_back({r,i});
		c[i] = c_;
	}

	sort(e.begin(), e.end());

	set<state> best;

	ll open = 0;

	for(auto [p, j] : e){
		if(j < 0){ // entrada no range j
			j *= -1;
			ll best_cur = 0;
			if(best.size()) best_cur = cur[best.begin()->i] + (p-ls[best.begin()->i]) * k;
			cur[j] = max(open, best_cur)-c[j];
			best.insert({j});
		}
		else{
			open = max(open, cur[j] + (p-ls[j]+1) * k);
			best.erase({j});
		}
	}

	cout << open << endl;

	return 0;
}

/*

dp[i] = max(dp[l[j]] + (l[i]-l[j]+1) * s), pra todo j com l[j] < i


*/