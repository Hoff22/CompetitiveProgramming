#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define fr first
#define sc second

using namespace std;

int seen[26][26];
int ans[N];

int main(){
	
	int n, k;
	scanf("%d%d", &n, &k);

	ans[0] = 0;

	for(int i = 1; i < n; i++){
		int best = 0;
		for(int j = 0; j < k; j++){
			if(seen[ans[i-1]][j] <= seen[ans[i-1]][best]){
				best = j;
			}
		}
		seen[ans[i-1]][best]++;
		ans[i] = best;
	}

	for(int i = 0; i < n; i++){
		char x = 'a' + ans[i];
		printf("%c", x);
	}
	printf("\n");

    return 0;

}