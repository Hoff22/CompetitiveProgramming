#include <bits/stdc++.h>

#define N 32768
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
	
	int dst[N+1];
	
	for(int i = 0; i <= 32768; i++){
		int t = i;
		dst[i] = 0;

		while(t % 2 == 0 and t){
			dst[i]++;
			t /= 2;
		}
	}

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);

		if(x == 0){
			printf("0 ");
			continue;
		}

		int mn = min(15 - dst[x], 32768 - x);
		for(int j = x; j <= 32768; j++){
			mn = min(mn, j - x + (15 - dst[j]));
		}

		printf("%d ", mn);
	}

	printf("\n");
    return 0;

}