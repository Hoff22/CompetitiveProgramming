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
    vector<ll> a(n);
    for(int i = 0 ; i < n; i++) cin >> a[i];

    ll mx, idx, ans, cur;
	ans = 0;

    k = min((int)a.size(), k);
	mx = 0;
	idx = 0;
	cur = 0;

	for(int i = 0; i < k-1; i++) cur += a[i];

	for(int i = 0; i+k-1 < a.size(); i++){
		cur += a[i+k-1];
		if(mx < cur){
			mx = cur;
			idx = i;
		}
		cur -= a[i];
	}

	ans += mx;
	a.erase(a.begin()+idx, a.begin()+idx+k);

	k = min((int)a.size(), k);
	mx = 0;
	idx = 0;
	cur = 0;

	for(int i = 0; i < k-1; i++) cur += a[i];

	for(int i = 0; i+k-1 < a.size(); i++){
		cur += a[i+k-1];
		if(mx < cur){
			mx = cur;
			idx = i;
		}
		cur -= a[i];
	}
	
    ans += mx;

    cout << ans << endl;

    return 0;

}

/*

  5 4 5 5 2 5 6 1

5 2
5 10 9 1 9


8 3
1 3 3 1 2 3 11 1

*/