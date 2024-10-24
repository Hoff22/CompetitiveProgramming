#include <bits/stdc++.h>

#define N 1000
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


long long a[N+1][N+1];
long long acc[N+1][N+1];
long long best[N+1][N+1];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	while(true){
		int n;
		cin >> n;

		if(n == 0) break;

		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				cin >> a[i][j];
				acc[i][j] = 0;
				best[i][j] = -INF;
			}
		}

		acc[0][0] = a[0][0];

		for(int i = 1; i < n; i++){
			for(int j = 0; j <= i; j++){
				acc[i][j] = a[i][j] + acc[i-1][j];
			}
		}

		
		best[n-1][0] = acc[n-1][0];
		
		long long ans = max(0ll, best[n-1][0]);

		for(int i = n-2; i >= 0; i--){
			best[i][0] = max(best[i+1][0], acc[i][0]);
			ans = max(ans, best[i][0]);
		}

		for(int j = 1; j <= n; j++){
			for(int i = n-1; i >= j; i--){
				if(i == n-1){
					best[i][j] = acc[i][j] + best[i-1][j-1];
				}
				else{
					best[i][j] = max(best[i+1][j], acc[i][j] + best[i-1][j-1]);
				}
				ans = max(ans, best[i][j]);
			}
		}
		cout << ans << endl;
	}
    return 0;

}