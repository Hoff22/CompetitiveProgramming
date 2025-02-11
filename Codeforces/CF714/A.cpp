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
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> ans;

	for(int i = 1; i <= n; i++) ans.push_back(i);

	if(n < 3 and k){
		printf("-1\n");
		return;
	}

	for(int i = 1; i < n-1; i+=2){
		if(k){
			if(i+2 >= n){
				swap(ans[i], ans[i+1]);
			}
			else{
				swap(ans[i], ans[i+2]);
			}
			k--;
		}
	}

	if(k) printf("-1\n");
	else{
		for(int i = 0; i < n; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}