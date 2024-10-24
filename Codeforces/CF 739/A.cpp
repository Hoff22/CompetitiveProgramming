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
	int k;
	scanf("%d", &k);

	int ans = 0;
	for(int i = 1; i <= 4000 and k; i++){
		if(i%3 == 0 or i%10 == 3) continue;
		ans = i;
		k--;
	}
	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
    return 0;

}