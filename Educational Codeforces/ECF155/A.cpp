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

void solve(){
	int n;
	cin >> n;
	vector<int> s(n);
	vector<int> e(n);

	for(int i = 0; i < n; i++){
		cin >> s[i] >> e[i];
	}

	int ans = s[0];

	for(int i = 1; i < n; i++){
		if(s[i] >= s[0]){
			ans = -1;
			break;
		}
	}

	if(ans == -1){
		ans = s[0];
		for(int i = 1; i < n; i++){
			if(s[i] >= ans and e[i] >= e[0]){
				ans = -1;
				break;
			}
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