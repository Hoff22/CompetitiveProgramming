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

	vector<int> a(n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int m = 0; (1<<m) <= 2*n; m++){
		for(int i = (1<<max(0,m-1))+1; i <= min(n,1<<m); i++){
			for(int j = (1<<max(0,m-1))+1; j <= i; j++){
				if(a[j] > a[i]){
					cout << "NO" << endl;
					return;
				}
			}
		}
	}

	cout << "YES" << endl;
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