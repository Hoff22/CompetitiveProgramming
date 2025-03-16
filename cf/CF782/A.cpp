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
	int r, b;
	cin >> r >> b;

	vector<int> a(b+1);

	while(r){
		for(int i = 0; i < a.size() and r; i++){
			a[i] += 1;
			r--;
		}
	}

	for(int i = 0; i < a.size(); i++){
		if(i) cout << 'B';
		while(a[i]--) cout << 'R';
	}

	cout << endl;


}
// 1010110000100000101


int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}