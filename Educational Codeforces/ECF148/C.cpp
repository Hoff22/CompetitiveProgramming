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

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	if(n == 1){
		cout << 1 << endl;
		return;
	}

	int last = 0;
	int rem = 0;
	for(int i = 1; i < n; i++){
		int prev = abs(a[last] - a[i]);
		int next = abs(a[i] - a[i+1]);

		if(last == 0){
			if(next == 0){
				rem++;
				continue;
			}
			else{
				last = i;
				continue;
			}
		}

		if(abs(a[last] - a[i+1]) == prev+next){
			// cout << "rem: " << i << endl;
			rem++;
			continue;
		}
		else{
			last = i;
			continue;
		}
	}

	cout << n-rem << endl;
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