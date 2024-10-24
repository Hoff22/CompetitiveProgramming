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

int main(){
	
	int n;
	scanf("%d", &n);

	int good = 1;

	for(int i = 0; i <= N; i++){
		a[i] = -INF;
	}

	for(int i = 0; i < n; i++){
		int x, c;
		scanf("%d %d", &x, &c);

		if(a[c] > x) good = 0;
		else{
			a[c] = x;
		}
	}

	if(good) printf("YES\n");
	else printf("NO\n");
    return 0;

}