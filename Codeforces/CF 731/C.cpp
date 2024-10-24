#include <bits/stdc++.h>

#define N 300
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int n, m, k;

int a[N+1];
int b[N+1];

void solve(){
	scanf(" %d %d %d", &k, &n, &m);

	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);

	vector<int> ans;
	int i = 1;
	int j = 1;
	while(i <= n or j <= m){
		//printf("%d %d %d\n", a[i], b[j], k);
		if(i<=n and a[i] <= k){
			ans.push_back(a[i]);
			k += (a[i] == 0);
			i++;
		}
		else if(j <= m and b[j] <= k){
			ans.push_back(b[j]);
			k += (b[j] == 0);
			j++;
		}
		else{
			printf("-1\n");
			return;
		}
	}
	
	for(int p = 0; p < ans.size(); p++){
		printf("%d ", ans[p]);
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