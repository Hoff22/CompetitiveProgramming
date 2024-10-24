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

	string t;
	cin >> t;

	for(int i = 0; i <= t.size()/2; i++){
			//cout << t[i] << " " << t[t.size()-i-1] << endl;
		if(t[i] == t[t.size()-i-1]){
			cout << (int)t.size() - 2*i << endl;
			return;
		}
	}

	cout << 0 << endl;
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