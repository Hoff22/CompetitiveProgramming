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
	int n;
	scanf("%d", &n);

	vector<int> v(n+1, 0);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i+1]);
	}

	vector<int> sum(n+1, 0);

	for(int i = 1; i <= n; i++){
		if(i % 2){
			sum[i] = sum[i-1] + v[i];
		}
		else{
			sum[i] = sum[i-1] - v[i];
		}
	}

	if(sum[n] == 0){
		printf("1\n1 %d\n", n);
		return;
	}

	for(int i = 0; i <= n; i++){
		printf("%d ", sum[i]);
	}
	printf("\n");

	for(int r = 1; r < n; r++){
		int seg1 = sum[r] - sum[0];
		int seg2;

		if(r % 2){
			seg2 = -(sum[n] - sum[r+1]) + v[r+1];
		}
		else{
			seg2 = (sum[n] - sum[r+1]) + v[r+1];
		}

		if(seg1 + seg2 == 0){
			printf("2\n");
			printf("%d %d\n", 1, r);
			printf("%d %d\n", r+1, n);
			return;
		}		
	}

	printf("-1\n");
}

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