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
	int n, m;
	scanf("%d %d", &n, &m);
	if(n > m){
		printf("0\n");
		return;
	}

	for(int i = 0; i <= m; i++){
		printf("%d\n", n ^ i);
	}
	printf("%d\n", min((n ^ m), n) + 1);


}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}