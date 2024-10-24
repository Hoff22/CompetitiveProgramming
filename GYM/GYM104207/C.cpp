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

void solve(int t){
	long long a, b, k;
	cin >> a >> b >> k;

	if(a > b){
		cout << "Case #" << t << ": " << k << endl;
		return;
	}
 
	long long l = 0;
	long long r = k;
	long long ans = 0;
	while(l <= r){
		long long m = (l+r) / 2;
 
		if(m*(a*9) + (k-m)*(a*11) - m*(b*11) >= 0){
			ans = m;
			l = m+1;
		}
		else{
			r = m-1;
		}
	}
 
	cout << "Case #" << t << ": " << ans << endl;
}

/*

  1   2   3   4   5    6    7   8   9   10 derrotas 
0 101 202 303 404 505  606  707 808 909 1010

0    1    2    3   4   5   6   7   8   9   10  11  12 vitorias
1010 910  

2
1


*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}