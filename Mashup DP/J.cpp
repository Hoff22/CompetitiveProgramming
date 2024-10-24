#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long n, m, k, x;
vector<int> g[N+1];

// C++ function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
void modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
       cout << "Division not defined";
    else
       cout << "Result of division is " << (inv * a) % m;
}
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

vector<int> next[N+1];

void dfs(int u, int p){
	for(int v : g[u]){
		if(v == p) continue;
		next[u].push_back(v);
	}
	if(next[u].size()==0) next[u].push_back(-1);
}

long long solve(int i, int xr, bool lx){
	if(i == -1){
		return 0;
	}

	long long r = 0;
	for(int v : next[i]){
		r = (((solve(v, xr, 0)*(m-1) % MOD) + solve(v, xr-1, 1) % MOD) + r) % MOD;
	}

	
}

int main(){
	
	scanf("%lld %lld", &n, &m);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
	}

	dfs(1, 0);

	scanf("%lld %lld", &k, &x);
    
    return 0;
}