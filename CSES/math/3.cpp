#include <bits/stdc++.h>

#define fi first
#define se second
#define MOD 1000000007

using namespace std;

/*
According the Fermat's little
a^(M - 1) = 1 (mod M) if M is a prime.

So if we rewrite B^C as x*(M-1) + y, then the
task of computing A^(B^C) becomes A^[x*(M-1) + y]
which can be written as A^[x*(M-1)] * A^y.
From Fermat's little theorem, we know A^[x*(M-1)] = 1 (mod M).
So task of computing A^(B^C) % M reduces to computing A^y

What is the value of y?
From B^C = x * (M - 1) + y,
y can be written as B^C % (M-1)

We can easily use the above theorem such that we can get
A ^ (B ^ C) % M = (A ^ y) %  M

Now we only need to find two things as:-
1. y = (B ^ C) % (M - 1)
2. Ans = (A ^ y) % M
*/

typedef long long ll;

// O(log_2(N))
long long fast_pow(long long a, long long b, long long mod){
    long long res = 1;
    while(b){
        if(b&1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res; 
}

void solve(){
	ll a, b, c;
	cin >> a >> b >> c;

	cout << fast_pow(a, fast_pow(b,c, MOD-1), MOD) << endl;
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
