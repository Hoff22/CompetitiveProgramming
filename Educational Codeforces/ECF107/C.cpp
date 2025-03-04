#include <bits/stdc++.h>

#define N 50
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int color[N+1];

int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);

	int mx = 0;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		if(color[x] == 0){
			color[x] = i;
		}
		mx = max(mx, x);
	}

	while(q--){
		int x;
		scanf("%d", &x);

		for(int i = 1; i <= mx; i++){
			if(color[i] < color[x]) color[i]++;
		}
		printf("%d ", color[x]);
		color[x] = 1;
	}
	printf("\n");

    return 0;

}