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

int a[N];

void solve(){
	printf("Case #%d: %d\n", q);
}

int main(){
	
	int t, n, q;
	scanf("%d%d%d", &t, &n, &q);
	
	while(t--){
		int ans[N+1];

		int x = n/2;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i!=j){
					query(i,j,x);
				}
			}
		}
	}
    return 0;

}