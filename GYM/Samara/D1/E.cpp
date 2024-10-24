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

int main(){
	
	int t;
	scanf("%d", &t);
	
	long long ans = 0;
	long long cur = 0;
	while(t--){
		
		long long a;
		scanf("%lld", &a);

		if(a + cur < 0){
			ans += abs(a + cur);
			cur = 0;
		}
		else{
			cur += a;
		}
	}

	printf("%lld\n", ans);
    return 0;

}