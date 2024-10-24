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

long long n;
long long solve(int h, int v, int moves){
	if(moves == n and h == 1 and v == 1){
		return 1;
	}
	if(moves > n) return 0;

	return solve(h*-1, v, moves+1) + solve(h, v*-1, moves+1); 
}

int main(){
	
	scanf("%lld", &n);

	printf("%lld\n", solve(1,1,1));

    return 0;

}