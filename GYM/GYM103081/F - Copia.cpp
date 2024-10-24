#include <bits/stdc++.h>

#define N 2021
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

ll p2[12];

int MOD;

ll dp(int n){
	//if(n <= 1) cout << "return 1" << endl;
	if(n <= 1) return 1;

	int q = n-1;

	ll r = 0;
	if(going_down){
		for(int i = 0; i <= q/2; i++){
			ll a = dp(i) * dp(q-i) * choose[q][i] % MOD;
			if(i == q-i) a /= 2;
			//cout << n << " " << i << " " << a << endl;
			r += a;
		}
	}
	else{
		for(int i = 0; i <= q; i++){
			ll a = dp(i, 0) * dp(q-i, 1) * choose[q][i] % MOD;
			if(i == q-i) a /= 2;
			//cout << n << " " << i << " " << a << endl;
			r += a;
		}
	}

	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, r;
    cin >> r >> n >> MOD;

    p2[0] = 1;
    for(int i = 1; i < 12; i++){
    	p2[i] = (p2[i-1] * 2) % MOD;
    }

    cout << dp(n-1) << endl;

    return 0;

}