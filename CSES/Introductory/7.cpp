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
	
	for(long long k = 1; k <= n; k++){
		if(k == 1) cout << 0  << endl;
		if(k == 2) cout << 6  << endl;
		if(k == 3) cout << 28 << endl;
		if(k == 4) cout << 96 << endl;
		if(k > 4){
			long long c = 0;
			c += (k-4)*(k-4)*8;
			c += (k-4)*4*6;
			c += (k-4)*4*4;
			c += 4*4;
			c += 8*3;
			c += 4*2;
			cout << (k*k*(k*k-1))/2 - c/2 << endl;
		}
	}
	
}

/*
0
6
28
96
252
550
1056
1848
*/

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}