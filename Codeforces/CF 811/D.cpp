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

int cnt[10][10];

void solve(){
	int n;
	scanf("%d", &n);

	memset(cnt, 0 , sizeof(cnt));
	vector<int> a(n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	for(int i = 0; i < n; i++){
		int seen[10][10];
		memset(seen, 0, sizeof(seen));
		//printf("%d: ", a[i]);
		while(!seen[(a[i]/10)%10][a[i]%10]){
			//printf("\t%d : %d\n", ((a[i]/10)%10)%2,a[i]%10);
			seen[(a[i]/10)%10][a[i]%10] = 1;

			cnt[(a[i]/10)%10][a[i]%10]++;				

			a[i] = a[i] + (a[i] % 10);
		}
	}

	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 9; j++){
			if(cnt[j][i] == n){
				printf("YES\n");
				return;
			}
		}
	}

	printf("NO\n");
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}