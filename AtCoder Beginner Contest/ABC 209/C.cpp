#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;


int main(){
	
	int n;
	scanf("%d", &n);
	vector<int> v(n);

	for(int i = 0; i < n; i++) scanf("%d", &v[i]);

	sort(v.begin(), v.end());

	long long ans = 1;
	for(int i = 0; i < n; i++){
		ans = (ans*max(0,(v[i]-i))) % MOD;
	}

	printf("%lld\n", ans);

    return 0;

}