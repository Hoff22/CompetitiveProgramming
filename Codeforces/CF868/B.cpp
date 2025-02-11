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
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n+1);

	int idx = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(abs(i-a[i])){
			if(abs(i-a[i]) % k){
				idx = i;
				cnt++;
			}
		}
	}

	if(cnt > 2){
		cout << "-1" << endl;
		return;
	}
	if(cnt == 0){
		cout << "0" << endl;
		return;
	}

	for(int i = 1; i <= n; i++){
		if(abs(a[idx] - i) % k == 0 and abs(idx - a[i]) % k == 0){
			cout << 1 << endl;
			return;
		}
	}
	cout << "-1" << endl;
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