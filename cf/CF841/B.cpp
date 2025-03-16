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

// C++ function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long *x, long long *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
long long modInverse(long long b, long long m)
{
    long long x, y; // used in extended GCD algorithm
    long long g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
long long modDivide(long long a, long long b, long long m)
{
    a = a % m;
    long long inv = modInverse(b, m);
    if (inv == -1)
       return -1;
    else
    	return (inv * a) % m;
}
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 

void solve(){
	long long n;
	scanf("%lld", &n);

	long long ans = 0;

	ans += (modDivide(((n*(n+1) % MOD)*(2*n+1) % MOD),6,MOD));

	n--;
	ans += (modDivide(((n*(n+1) % MOD)*(n+2) % MOD),3,MOD));

	ans *= 2022;
	ans %= MOD;

	printf("%lld\n", ans);
}

/*

0 1 3 6 10 15 


* *
* *

1 2 = 3 + 4  = 7
2 4


1 2 3
2 4 6  = 7 + 6 + 9 = 22
3 6 9 

0 1 2 4 6 9 12 16  


(1 * 1) + (1 * 2) + (2 * 2) + (2 * 3) + (3 * 3)

(0 + 1 + 2) * 1

(1 + 2 + 3) * 2


(1 + 2 + 3) * (1 + 2 + 3) =

(1 * 1) + (1 * 2) + (1 * 3) + (1 * 2) + (2 * 2) + (2 * 3) + (1 * 3) + (2 * 3) + (3 * 3)


2 3 6

1 4 9 5

*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}