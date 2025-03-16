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

/* O(Log(B)). */
long long fast_exp(long long a, long long b, long long m) {
    long long ans = 1; // Base case.

    // In case a >= m.
    a %= m;

    // Decomposing b in binary. Multiplying the answer by a^1, a^2, a^4, a^8, ...
    while (b > 0) {
        // If current bit is set.
        if (b & 1ll) {
            ans = (ans * a) % m;
        }

        b >>= 1ll;       // Next bit.
        a = (a * a) % m; // Next power of a.
    }

    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    long long a, b, m;

    while(scanf(" %lld %lld %lld", &a, &b, &m) != EOF){

    	printf("%lld\n", fast_exp(a, b, m));

    }

    return 0;

}