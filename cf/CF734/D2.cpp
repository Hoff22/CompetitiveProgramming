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
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	if(n%2){
		if(k >= m/2 and (k-m/2)%2 == 0){
			printf("YES\n");
		}
		else{ 
			printf("NO\n");
			return;
		}
	}
	else if(m%2){
		if(k%2 == 0 and k <= n*(m-1)/2){
			printf("YES\n");
		}
		else{ 
			printf("NO\n");
			return;
		}
	}
	else{
		if(k%2 == 0){
			printf("YES\n");
		}
		else{ 
			printf("NO\n");
			return;
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}