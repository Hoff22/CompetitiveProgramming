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

	if(n % 2){
		for(int i = 0; i < n; i++){
			printf("1 ");
		}
		printf("\n");
	}
	else{
		
		int x = 0;
		int s = 0;

		int p = 2;

		while((p*n - p) % (n-1) != 0){
			p++;
		}

		for(int i = 0; i < n-1; i++){
			printf("%d ", (p*n - p) / (n-1));
			x ^= (p*n - p) / (n-1);
			s += (p*n - p) / (n-1);
		}
		printf("%d", p);
		printf("\n");

		x ^= p;
		s += p;

		printf("%d %d\n", x, s / n);
	}

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