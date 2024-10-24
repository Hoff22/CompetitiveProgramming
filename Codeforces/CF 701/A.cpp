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

	ll x, y; cin >> x >> y;

	long long ans = 0;

	for(ll k = 1; k * k <= x and k < y; k++){
		/*
		
		
		k * (b+1) = a

		b + 1 = x / k

		b = (x/k) - 1
	

		upper_b = (x/k) - 1;
		lower_b = 

		(y-k) 
	
		*/

		ll l = k+1;
		ll r = y;
		ll res = k;

		while(l <= r){
			ll b = l + (r-l)/2;
			if((k*b + k <= x)){
				res = b;
				l = b+1;
			}
			else{
				r = b-1;
			}
		}

		// cout << " " << res << " : " <<  k << endl; 

		ans += res - (k+1) + 1;

		// for(int b = k+1; b <= (x/k) - 1 and b <= y; b++){

		// 	// a = k*b + k
		// 	// if((k*b + k <= x)) cout << " " << k*b + k << " " << b << " : " << k << endl;
		// 	ans += (k*b + k <= x);

		// }
	}

	cout << ans << endl;
	/*


		3, 2 -> 1
		4, 3 -> 1
		8, 3 -> 2



		12 4

		12 / 1 = 12
		12 / 2 = 6   -->   6, 18, ... , 
		12 / 3 = 4
		12 / 4 = 3



		b m -> a = m*b + m

		m*b + m <= x

		a/b = m + m/b
		a/b = m + m/b

		a/b = a%b = k

		a/b = k

		k*b + k = a  

	*/

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}