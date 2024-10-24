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
	int a, b;
	cin >> a >> b;
	if(a < b) swap(a,b);

	int x = a - (a-b)*2;
	int y = b - (a-b);

	if(x>=0 and y>=0 and (x+y)%3 == 0){
		cout << "YES" << endl;
	}
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