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

	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	long long ans = 0;
	long long sum = 0;
	int i, j;
	for(i = 0, j = n-1; i < j; i++){
		long long x = min(a[i], a[j] - sum);

		ans += x;
		sum += x;

		// cout << i << " " << j << " | " << sum << " " << ans << endl;
		if(sum == a[j]){
			ans++;
			j--;
			sum = 0;
		}

		a[i] -= x;

		if(a[i] != 0){
			i--;
		}
	}

	if(sum){
		a[i] -= sum;
	}

	if(i == j){
		ans += (a[i]+1)/2 + (a[i] > 1 or (a[i] == 1 and sum));
	}

	cout << ans << endl;
}

/*

13 2
12 3
11 4
10 5
9  6
8  7
____
1 0
0 0


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