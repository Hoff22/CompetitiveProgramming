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

unsigned long long solve(){
	unsigned long long n;
	cin >> n;
	if(n == 0) return 1;
	if(n == 1) return 9;
	if(n == 2) return 41;
	if(n == 3) return 109;
	return 14ll*n*n - 6ll*n + 5ll;
}

/*

n

0 1  2^0 + 1    = 1                    2^0
1 9  2^3 + 1    = 2^3 + 1            2^3 + 2^0
2 41 2^5 + 1   = 64 / 2 + 1
3 41 2^6 + 1        =           2^3*2^3*2^3*2^3*2^3*2^3*2^3 - 2^4*2^4*2^4*2^4*2^4*2^4 + 1
4    2^6 + 1
5
6
7


*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
    return 0;

}