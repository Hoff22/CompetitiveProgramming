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
	long long n, x, y, fx, fy;
	cin >> n >> x >> y >> fx >> fy;

	if(x > y) swap(x,y);
	if(fx > fy) swap (fx, fy);

	long long a, b;

	if(x <= n/2 and y <= n-x+1) a = x;
	else a = (n-y+1);

	if(fx <= n/2 and fy <= n-fx+1) b = fx;
	else b = (n-fy+1);

	cout << abs(a-b) << endl;

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