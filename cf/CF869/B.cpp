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
//18:40!!
void solve(){
	int n;
	cin >> n;

	if(n == 1){
		cout <<1  <<endl;
		return;
	}

	if(n%2){
		cout << -1 << endl;
		return;
	}

	vector<int> ans;

	int a = 2;
	int b = 1;
	for(int i = 0; i < n; i++){
		if(i%2){
			ans.push_back(b);
			b+=2;
		}
		else{
			ans.push_back(a);
			a+=2;
		}
	}

	// for(int k = 2; k <= n; k++){
	// 	for(int i = 0; i+k-1 < n; i++){
	// 		long long acc =0;
	// 		for(int j = i; j-i+1 <= k; j++){
	// 			acc += ans[j];
	// 		}

	// 		if(acc % k == 0){
	// 			cout << "FAIL " << k << endl;
	// 			break;
	// 		}
	// 	}
	// }

	for(int i : ans) cout << i << " ";
		cout << endl;
}

/*

	1 2 3

	2 1 4 3

	2 1 4 3 6 5


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