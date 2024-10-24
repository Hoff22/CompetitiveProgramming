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

	if(n == 1){
		cout << 1 << endl;
		return;
	}

	if(n%2){
		cout << -1 << endl;
		return;
	}

	int s = 2;
	int b = n-1;

	cout << n << " ";

	for(int i = 0; i < n-1; i++){
		if(i%2){
			cout << s << " ";
			s += 2;
		}
		else{
			cout << b << " ";
			b -= 2;
		}
	}

	cout << endl;
}

/*

8

8 1 2 3 4 5 6 7

0 1 3 6 2 7 5 4

10 1 2 3 6 7 8 5
0  1 3 6 2 9 7

10 9 2 7 4 5 6 3 8 1
0  9 1 8 2 7 3 6 4 5


8 7 2 5 4 3 6 1
0 7 1 6 2 5 3 4


6 5 2 3 4 1
0 5 1 4 2 3

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