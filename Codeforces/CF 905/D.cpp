#include <bits/stdc++.h>

#define N 200000
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

int n, m;
vector<int> a;
vector<int> b;

int check(int x){
	a[0] = x;

	vector<int> as = a;
	sort(as.begin(), as.end());
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		auto j = upper_bound(b.begin(), b.end(), as[i]);
		ans = max(ans, (int)(j - b.begin() - i));
	}

	return ans;
}

void solve(){
	cin >> n >> m;

	a.assign(n,0);
	b.assign(n,0);

	for(int i = 0; i < n-1; i++){
		cin >> a[i+1];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	sort(b.begin(), b.end());

	int ans1 = check(1);

	int l = 1;
	int r = m;
	int x = 0;
	while(l <= r){
		int md = (r-l)/2 + l;

		// cout << "md: " << md << " | " << check(md) << endl;

		if(check(md) > ans1){
			r = md-1;
		}
		else{
			x = md;
			l = md+1;
		}
	}

	// cout << "x: " << x << endl;

	if(check(x+1) == ans1){
		cout << 1ll * ans1 * m << endl;
	}
	else{
		cout << 1ll * x * ans1 + 1ll * (m-x) * (ans1+1) << endl;
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