#include <bits/stdc++.h>

#define N 2000
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
void shift_l(int vezes, int n){
	int b[N+1];
	for(int i = n; i > 0; i--){
		int npos;
		if(i - vezes < 1){
			npos = n + (i - vezes);
		}
		else{
			npos = i - vezes;
		}

		b[npos] = a[i];
	}

	for(int i = 1; i <= n; i++){
		a[i] = b[i];
	}
}

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", (a+i));
	}

	vector<int> ans(n+1);

	for(int i = n; i > 0; i--){

		int j = 1;
		for(; j < i; j++){
			if(a[j] == i) break;
		}

		if(j == i){
			ans[i] = 0;
		}
		else{
			ans[i] = j;
			shift_l(j, i);
		}
	}

	for(int v = 1; v <= n; v++){
		printf("%d ", ans[v]);
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