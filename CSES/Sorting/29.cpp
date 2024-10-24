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

void solve(){
	int n;
	cin >> n;

	vector<int> a(n);

	int ans = 0;
	set<int> s;
	for(int i = 0, j = 0; j < n; j++){
		cin >> a[j];
		while(i < j and s.count(a[j])){
			s.erase(a[i]);
			i++;
		}
		s.insert(a[j]);
		ans = max(ans, (int)s.size());
	}

	cout << ans << endl;
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