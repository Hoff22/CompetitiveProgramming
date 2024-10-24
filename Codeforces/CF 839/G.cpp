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

void solve(){
	long long n, x, y;
	scanf("%lld %lld %lld", &n, &x, &y);

	vector<long long>a(n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	sort(a.begin(), a.end());

	long long ans = 0;

	for(long long i = 0; i < n; i++){

		int k = 2*i - n;

		// printf("%lld : %lld : %lld\n", i, x, ans);

		if(y == x) break;

		if(a[i] > y){
			if(k <= 0) break;
			ans += (n-i);
			x 	-= (n-i);

			// printf("\t %lld : %lld\n", x, ans);

			long long r = ((y - i) - x + (k-1)) / k;

			ans += r * n;
			x 	+= r * k;

			// printf("\t %lld : %lld\n", x, ans);

			ans += min(y - x, i);
			x 	+= min(y - x, i);
			
			// printf("\t %lld : %lld\n", x, ans);
			break;
		}

		if(a[i] > x){
			if(k <= 0) break;
			ans += (n-i);
			x 	-= (n-i);

			// printf("\t %lld : %lld\n", x, ans);

			long long r = ((a[i] - i) - x + (k-1)) / k;

			ans += r * n;
			x 	+= r * k;

			// printf("\t %lld : %lld\n", x, ans);

			ans += min(y - x, i);
			x 	+= min(y - x, i);
			
			// printf("\t %lld : %lld\n", x, ans);
		}

		if(y == x) break;

		x++;
		ans++;
		
	}

	if(a[n-1] < x and x < y){
		ans += (y-x);
		x = y;
	}

	if(x == y){
		printf("%lld\n", ans);
	}
	else{
		printf("-1\n");
	}
}

/*

7 2 10
3 1 9 2 5 20 8

i:     0  1  2  3  4  5  6 *
a:     1  2  3  5  8  9  20 *
x:     2  3  4  5  6
k:    -5 -3 -1   1   3   5    
r:  0  0  

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