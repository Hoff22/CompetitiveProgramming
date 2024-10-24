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
	long long n;
	cin >> n;

	while(n != 1){
		cout << n << " ";
		if(n%2) n = n * 3 + 1;
		else n /= 2;
	}	
	cout << n << endl;
}

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