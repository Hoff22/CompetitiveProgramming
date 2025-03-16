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
	int n, k;

	cin >> n >> k;

	k-=2;

	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}


	int cur = 0;
	for(int i = 2; i <= k; i++){
		cur += (a[i-1] < a[i] and a[i] > a[i+1]);
	}

	int ans = 2;
	int best = cur;
/*

8 6
1 2 4 1 2 4 1 2
\ --- /
1 2 3 4 5 6 7 8

*/

	for(int i = k+1; i < n; i++){
		cur += (a[i-1] < a[i] and a[i] > a[i+1]);

		int j = i-k+1;

		if(cur > best){
			ans = j;
			best = cur;
		}

		cur -= (a[j-1] < a[j] and a[j] > a[j+1]);
	}
	


	cout << best+1 <<" "<< ans-1 << endl;


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