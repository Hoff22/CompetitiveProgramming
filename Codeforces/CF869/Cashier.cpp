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
// 18:28!!

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, t;
    cin >> n >> l >> t;

    vector<int> a(n+1), b(n+1);

    int ans = 0;

    for(int i = 1; i <= n; i++){
    	cin >> a[i] >> b[i];
    	ans += (a[i] - (a[i-1]+b[i-1])) / t;
    }

    ans += (l - (a[n]+b[n])) / t;

    cout << ans << endl;

    return 0;

}