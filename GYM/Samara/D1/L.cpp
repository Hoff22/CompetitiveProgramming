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

int a[N+1];
int n;
int sum = 0;

long long solve(int i){
	if(i == n) return sum;



	return max(solve(i+1) - (n-i+1), solve(i+1) - a[i]);


}

int main(){
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);	
		sum += a[i];
	} 

	
		printf("%lld\n", solve(0));

    return 0;

}