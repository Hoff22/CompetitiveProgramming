#include <bits/stdc++.h>

#define N 300000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int ans[N+1];

int al[N+1];
int ar[N+1];

void solve(){
	
	int n, k;
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++) ans[i] = INF;

	vector<pair<int,int>> a(k, {0,0});

	for(int i = 0; i < k; i++){
		scanf("%d", &a[i].second);
	}
	for(int i = 0; i < k; i++){
		scanf("%d", &a[i].first);
	}

	for(int i = 0; i < k; i++){
		ans[a[i].second] = a[i].first;
	}


	int last = INF;
	for(int i = 1; i <= n; i++){
		if(ans[i] < last) last = ans[i];
		else ans[i] = last;
		last++;
	}
	
	last = INF;
	for(int i = n; i >= 1; i--){
		if(ans[i] < last) last = ans[i];
		else ans[i] = last;
		last++;
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
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