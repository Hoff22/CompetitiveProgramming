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
int cnt[N+1];

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c ", &c);
		cnt[i] = 0;
		a[i] = (c == '1');
		//printf("%d",a[i]);
	}
	//printf("\n");

	if(k == 0){
		for(int j = 0; j < n; j++){
			printf("%d", a[j]);
		}
		printf("\n");
		for(int j = 0; j < n; j++){
			printf("%d ", 0);
		}
		printf("\n");
		return;
	}

	int flips = 0;
	if((k % 2 == 0 and a[0] == 0) or (k % 2 == 1 and a[0] == 1)){
		flips++;
		cnt[0]++;
		k--;
	}

	for(int i = 1; i < n and k; i++){
		if((a[i] + flips) % 2 != abs((a[0] + flips - cnt[0]) % 2)){
			//a[0] = (a[i] + flips) % 2;
			flips++;
			k--;
			cnt[i]++;
		}
	}

	// printf("cnt %d: ", k);
	// for(int l = 0; l < n; l++){
	// 	printf("%d", (a[l] + flips - cnt[l]) % 2);
	// }
	// printf("\n");

	for(int j = 0; j < n; j++){
		if(abs((a[j] + flips - cnt[j]) % 2) != abs((a[0] + flips - cnt[0]) % 2) or j == n-1){
			cnt[j] += k;
			flips += k;
			for(int l = 0; l < n; l++){
				printf("%d", abs((a[l] + flips - cnt[l]) % 2));
			}
			printf("\n");
			for(int l = 0; l < n; l++){
				printf("%d ", cnt[l]);
			}
			break;
		}
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}