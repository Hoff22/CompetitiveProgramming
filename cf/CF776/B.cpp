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
	int l, r, a;
	scanf("%d %d %d", &l, &r ,&a);

	int menosum = ((r / a) * a) - 1;

	if(menosum < l){
		printf("%d\n", r/a + (r % a));
	}
	else{
		printf("%d\n", max(r/a + (r % a), menosum / a + (menosum % a)));
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