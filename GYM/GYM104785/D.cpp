#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	long long ans = 0;
	for(int i = n-1, j = 0; i-j >= 2; i-=2, j++){
		ans += a[i-1];
	}

	cout << ans << endl;
}