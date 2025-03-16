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

int a[3][2];

void solve(){
	for(int i = 0; i < 3; i++){
		cin >> a[i][0] >> a[i][1];
	}

	int acc = 0;
	for(int i = 1; i <= 100; i++){
		int mx = 0;
		for(int k = 0; k < 3; k++){
			if(a[k][1] >= i) mx = max(mx, a[k][0]);
		}
		acc += mx;
	}

	cout << acc << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	
	while(t--){
		solve();
	}
    return 0;

}