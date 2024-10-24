#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;


void solve(){
	int n;
	scanf("%d", &n);
	vector<int> g;
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		g.push_back(x);
	}

	sort(g.begin(), g.end());

	int l = 0;
	int r = n-1;
	for(int i = 0; i < n-1; i++){
		int j = i+1;
		if(g[j] - g[i] <= g[r] - g[l]){
			l = i;
			r = j;
		}
	}

	if(n == 2){
		printf("%d %d\n", g[0], g[1]);
		return;
	}

	for(int i = r; i < n; i++){
		printf("%d ", g[i]);
	}
	for(int i = 0; i <= l; i++){
		printf("%d ", g[i]);
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