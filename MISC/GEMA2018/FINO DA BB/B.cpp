#include <bits/stdc++.h>

#define N 200000
#define INF 0x3f3f3f3f

using namespace std;

int n, q;

long long a[N+1];
long long k[N+1];

int lb(int start, long long target){
	int l = start;
	int r = n;
	int ans = -1;

	while(l <= r){
		int m = l + ((r - l) / 2);

		if(a[m] > target){
			ans = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}

	return ans;
}

int main(){

	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; i++){
		long long x;
		scanf("%lld", &x);

		a[i] = a[i-1] + x;
	}
	for(int i = 1; i <= q; i++){
		long long y;
		scanf("%lld", &y);

		k[i] = k[i-1] + y;
	}

	int l = 1;
	long long correction = 0;
	for(int i = 1; i <= q; i++){
		l = lb(l, k[i] - correction);

		if(l == -1){
			printf("%d\n", n);
			l = 1;
			correction = k[i];
			continue;
		} 

		printf("%d\n", n - (l - 1));
	}
	// 1 3 6 10
	//
	return 0;
}