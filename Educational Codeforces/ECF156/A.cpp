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

	for(int i = 1; i <= 30; i++){
		for(int j = i+1; j <= 30; j++){
			if(i%3 and j%3 and (n-i-j)%3 and (n-i-j) != i and (n-i-j) != j and (n-i-j) > 0){
				cout << "YES" << endl;
				cout << i << " " << j << " " << n-i-j << endl;
				return;
			}
		}
	}

	cout << "NO" << endl;
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