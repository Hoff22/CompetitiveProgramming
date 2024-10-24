#include <bits/stdc++.h>

#define N 200000
#define MAX 100000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int a[N+1];
unordered_set<int> freq;

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] += a[i-1];
		freq.insert(a[i]);
	}

	if(a[n] % 3 != 0){
		printf("0\n");
		return 0;
	}

	int ans = 0;
	int of = a[n]/3;
	for(int i = 1; i <= n; i++){
		if(freq.count(a[i]+of) and freq.count(a[i]+of+of)) ans++;
	}

	printf("%d\n", ans);
	
    return 0;

}