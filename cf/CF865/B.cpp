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

	vector<int> a(n);
	vector<int> b(n);

	a[0] = 2*n;
	b[n-1] = 2*n-1;

	int x = 2*n-2;
	for(int i = 2; i < n; i++){
		if(i%2==0){
			a[i] = x--;
		}
		else{
			b[i-2] = x--;
		}
	}
	x = 1;
	for(int i = 0; i < n; i++){
		if(i%2){
			a[i] = x++;
		}
		else{
			b[i] = x++;
		}
	}
	
	for(int i : a) cout << i << " ";
	cout << endl;
	for(int i : b) cout << i << " ";
	cout << endl;
}

/*

8 1 6 3
4 5 2 7

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