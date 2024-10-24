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
	
	long long r;
	r = 0;
	while(t--){
		long long i, j;
		scanf("%lld %lld", &i, &j);

		if(i >= r){
			r = i+j;
		}
		else{
			r += j;
		}
	}

	printf("%lld\n", r);

    return 0;

}