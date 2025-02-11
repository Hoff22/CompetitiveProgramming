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

void solve(){
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> mx(n);
	int good = 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];

		if(i > 0){
			mx[i] = mx[i-1];
			if(mx[i] - 1 > a[i]){
				// cout << i << " " << mx[i] << endl;
				good = 0;
			}
			mx[i] = max(mx[i], a[i]);
		}
		else{
			mx[i] = a[i];
		}
	}

	if(good) cout << "YES" << endl;
	else cout << "NO" << endl;
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