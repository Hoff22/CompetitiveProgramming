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

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<ll> s(n+1, 0ll);

    for(int i = 1; i <= n; i++){
    	ll x;
    	cin >> x;
    	s[i] = s[i-1] + x;
    }

    long long mx = 0;
    for(int i = k; i < n; i++){
    	int j = i-k+1;
    	mx = max(mx, s[i] - s[j-1];)
    }

    cout << mx << endl;

    return 0;

}