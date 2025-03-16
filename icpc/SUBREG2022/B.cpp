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

/* O(Log(min(a, b))) - Extended Euclidean Algorithm.
   Returns a solution to a * x + b * y = gcd(a, b).
   Returns |x| <= |a / gcd(a, b)|, |y| <= |b / gcd(a, b)| and gcd(a, b). */
tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    long long x, y, gcd;

    if (a == 0) {
        return {b, 0, 1};
    }

    tie(gcd, x, y) = extended_gcd(b % a, a);

    return {gcd, y - (b / a) * x, x};
}

/* O(Log(M)) - Returns the modular multiplicative inverse of a mod m, if it exists.
Returns x that satisfies a * x = 1 (mod m) if a and m are coprime. Returns 0 otherwise. */
long long modular_inverse(long long a, long long m) {
    long long gcd, x, y;

    tie(gcd, x, y) = extended_gcd((a % m + m) % m, m);

    if (gcd != 1) {
        return 0;
    }

    return (x % m + m) % m;
}

ll l[3];
ll r[3];
ll DP[31][8][8];

ll dp(int shift, int l_pref, int r_pref){
	if(shift < 0) return 1;

	// se l_pref[i] and   l[i]>>shift  == 1
	// se r_pref[i] and !(l[i]>>shift) == 0

	if(DP[shift][l_pref][r_pref] != -1) return DP[shift][l_pref][r_pref];

	ll ans = 0;

	int curL = 0;
	int curR = 0;
	for(int i = 0; i < 3; i++){
		curL += (((l[i]>>shift)&1)<<i);
		curR += (((r[i]>>shift)&1)<<i);
	}

	// cout << (((4>>2)&1)<<1) << endl;
	// cout << "shift: " << shift  << endl;
	// cout << " l[0]: " << l[0] << " l[1] " << l[1] << " l[2] " << l[2] << endl; 
	// cout << " r[0]: " << r[0] << " r[1] " << r[1] << " r[2] " << r[2] << endl; 
	// cout << "curl: " << curL << " | curR: " << curR << endl << endl;

	for(int nxt = 0; nxt < 8; nxt++){
		if(__builtin_popcount(nxt) % 2) continue;

		#define l_pref(x) ((l_pref>>x) & 1)
		#define r_pref(x) ((r_pref>>x) & 1)
		#define nxt(x) ((nxt>>x)&1)
		#define curL(x) ((curL>>x)&1)
		#define curR(x) ((curR>>x)&1)

		for(int n_l_pref = 0; n_l_pref < 8; n_l_pref++){
			
			#define n_l_pref(x) ((n_l_pref>>x) & 1)

			bool goodL = 1;
			for(int i = 0; i < 3; i++){
				if(!l_pref(i) and n_l_pref(i)) goodL = 0;
				if(l_pref(i) and n_l_pref(i) and (nxt(i) != curL(i))) goodL = 0;
				if(l_pref(i) and !n_l_pref(i) and (nxt(i) == curL(i))) goodL = 0;
				if(l_pref(i) and curL(i) and !nxt(i)) goodL = 0;
			}

			if(!goodL) continue;

			for(int n_r_pref = 0; n_r_pref < 8; n_r_pref++){
			
				#define n_r_pref(x) ((n_r_pref>>x) & 1)
				
				bool goodR = 1;
				for(int i = 0; i < 3; i++){
					if(!r_pref(i) and n_r_pref(i)) goodR = 0;
					if(r_pref(i) and n_r_pref(i) and (nxt(i) != curR(i))) goodR = 0;
					if(r_pref(i) and !n_r_pref(i) and (nxt(i) == curR(i))) goodR = 0;
					if(r_pref(i) and !curR(i) and nxt(i)) goodR = 0;
				}

				if(!goodR) continue;

				//cout << "nxt: " << nxt << " | n_l_pref: " << n_l_pref << " | n_r_pref: " << n_r_pref << endl; 
				ans = (ans + dp(shift-1, n_l_pref, n_r_pref)) % MOD;
			}			
		}
	}

	return DP[shift][l_pref][r_pref] = ans;

	// make this a 1 in the first and second
	// make this a 1 in the first and third
	// make this a 1 in the second and third


}

// 1 1 1 1 1 1

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    for(int i = 0; i < 3; i++){
		cin >> l[i];
		cin >> r[i];
	}

	memset(DP, -1, sizeof(DP));

	ll total = r[0]-l[0]+1;
	total *= (r[1] - l[1]+1);
	total %= MOD;
	total *= (r[2] - l[2]+1);
	total %= MOD;

	ll amt = (total - dp(30, 8-1, 8-1) + MOD) % MOD; 

	cout << (amt * modular_inverse(total, MOD)) % MOD << endl;

    return 0;

}