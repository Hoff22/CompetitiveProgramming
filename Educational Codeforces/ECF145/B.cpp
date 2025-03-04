#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000000000000ll
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

/* O(Log(B)). */
long long fast_exp(long long a, long long b) {
    long long ans = 1; // Base case.

    // In case a >= m.

    // Decomposing b in binary. Multiplying the answer by a^1, a^2, a^4, a^8, ...
    while (b > 0) {
        // If current bit is set.
        if (b & 1ll) {
            ans = (ans * a);
        }

        b >>= 1ll;       // Next bit.
        a = (a * a); // Next power of a.
    }

    return ans;
}

void solve(){
	long long n;
	cin >> n;

	if(n == 0){
		cout << 0 << endl;
		return;
	}

	long long l = 0;
	long long r = 1000000000;
	long long ans1 = 0;

	while(l <= r){
		long long m = (l+r) / 2;

		if(m*m >= n){
			ans1 = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	cout << ans1-1 << endl;

}

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

/*
110110001001100010001010100111110001110011000100101001100010
111010110111100110100010110001
*/