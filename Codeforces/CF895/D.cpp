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
	long long n, x, y;
	cin >> n >> x >> y;

	long long a = n/x - (n/lcm(x,y));
	long long b = n/y - (n/lcm(x,y));

	//cout << a << " " << b << endl;
	//cout << n*(n+1)/2 << " - " << ((n-a)*(n-a+1)/2) << endl;
	long long ans = ((n*(n+1)) - (((n-a)*(n-a+1)))) - ((b*(b+1)));

	cout << ans/2 << endl;
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