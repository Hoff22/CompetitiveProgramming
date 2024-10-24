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
	
	long long a,b,c;

	scanf("%lld%lld%lld", &a, &b, &c);

	long long ansA = (2*b - c) - a;
	long long ansB = ((c+a)/2) - b;
	long long ansC = (2*b - a) - c;

	long long ans = INFll;
	if(ansA >= 0){
		ans = ansA;
	}
	if(ansB >= 0){
		ans = min(ans, ansB);
	}
	if(ansC >= 0){
		ans = min(ans, ansC);
	}

	printf("%lld\n", ans);

    return 0;

}