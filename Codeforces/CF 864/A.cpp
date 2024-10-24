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
	int n, m;

	int x1,x2,y1,y2;

	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;

	int a = min(n,m);

	int b = 4;
	int c = 4;

	if(x1 == 1) b--;
	if(y1 == 1) b--;
	if(x1 == n) b--;
	if(y1 == m) b--;

	if(x2 == 1) c--;
	if(y2 == 1) c--;
	if(x2 == n) c--;
	if(y2 == m) c--;

	cout << min({a,b,c}) << endl;	
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