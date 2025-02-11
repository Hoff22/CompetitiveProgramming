#include <bits/stdc++.h>

#define N 200000
#define T 450
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

int cnt[1000000+1];

void solve(){
	int n,q;
	cin >> n >> q;

	vector<int> a(n+1);
	vector<tuple<int,int,int>> qs(q);
	vector<int> ans(q);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]] = 0;
	}

	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		qs[i] = {l,r,i};
	}
	sort(qs.begin(), qs.end(), [&](tuple<int,int,int> i, tuple<int,int,int> j){
		int li, ri, idxi;
		int lj, rj, idxj;
		tie(li,ri,idxi) = i;
		tie(lj,rj,idxj) = j;
		return make_pair(li / T, ri) < make_pair(lj / T, rj);
	});

	int odds = 0;

	int cl = 1;
	int cr = 0;
	for(auto [l,r,i] : qs){
		while(cl < l){
			if(cnt[a[cl]] % 2) odds--;
			else odds++;
			cnt[a[cl]]--;
			cl++;
		}
		while(cl > l){
			cl--;
			cnt[a[cl]]++;
			if(cnt[a[cl]] % 2) odds++;
			else odds--;
		}
		while(cr < r){
			cr++;
			cnt[a[cr]]++;
			if(cnt[a[cr]] % 2) odds++;
			else odds--;
		}
		while(cr > r){
			if(cnt[a[cr]] % 2) odds--;
			else odds++;
			cnt[a[cr]]--;
			cr--;
		}
		// for(auto [x, c] : cnt){
		// 	cout << "("<<x<<","<<c<<") ";
		// }
		// cout << endl;
		// cout << l << " " << r << ": " << odds.size() << endl; 
		ans[i] = !odds;
	}

	for(int i : ans){
		if(i) cout << "YES\n";
		else cout << "NO\n";
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