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
	int n, x;
	cin >> n >> x;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;
	for(int i = 0, j = n-1; i <= j;){
		if(a[i] + a[j] <= x){
			i++; j--;
		}
		else{
			j--;
		}
		ans++;
	}

	cout << ans << endl;
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