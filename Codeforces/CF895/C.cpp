#include <bits/stdc++.h>

#define N 10000000
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
	int l,r;
	cin >> l >>r;

	for(long long i = 2; i * i <= r; i++){
		if(r%i == 0){
			cout << (r-i) << " " << i << endl;
			return;
		}
	}

	if(r>l){
		r--;
		if(r-2 > 0){
			cout << r-2 << " " << 2 << endl;
			return;			
		}
	}

	cout << -1 << endl;
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