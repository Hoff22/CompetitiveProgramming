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

void solve(){
	ll dx, dy;
	cin >> dx >> dy;

	ll m = 1;

	for(int i = 1; i * i <= dx; i++){
		ll d1 = i;
		ll d2 = ceil(1.0*dx/i);

		if((ll)ceil(1.0*dx/m) + (ll)ceil(1.0*dy/m) + m-1 >
			(ll)ceil(1.0*dx/d1) + (ll)ceil(1.0*dy/d1) + d1-1) m = d1;
		if((ll)ceil(1.0*dx/m) + (ll)ceil(1.0*dy/m) + m-1 >
			(ll)ceil(1.0*dx/d2) + (ll)ceil(1.0*dy/d2) + d2-1) m = d2;
	}

	for(int i = 1; i * i <= dy; i++){
		ll d1 = i;
		ll d2 = ceil(1.0*dy/i);

		if((ll)ceil(1.0*dx/m) + (ll)ceil(1.0*dy/m) + m-1 >
			(ll)ceil(1.0*dx/d1) + (ll)ceil(1.0*dy/d1) + d1-1) m = d1;
		if((ll)ceil(1.0*dx/m) + (ll)ceil(1.0*dy/m) + m-1 >
			(ll)ceil(1.0*dx/d2) + (ll)ceil(1.0*dy/d2) + d2-1) m = d2;
	}

	cout << m-1 + (ll)ceil(1.0*dx/m) + (ll)ceil(1.0*dy/m) << endl;
}

/*

= dx/m



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