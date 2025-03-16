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
	int x,y;
	cin >> x >> y;
	if(x == y-1){
		cout << "YES" << endl;
	}
	else{
		if(y < x and (x-y) % 9 == 8){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}

/*
6
2 2 4 5 3 2
.
. .
. . . .



*/

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