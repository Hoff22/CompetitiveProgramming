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

	int par = 1;
	int imp = 0;
	int cur = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		cur += x;

		if(cur %2){
			ans += par;
			imp++;
		}
		else{
			ans += imp;
			par++;
		}
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}