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

	vector<int> v(n+1);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}
	
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		int j = v[i]-i;
		while(j <= n){
			if(j > i and 1ll*v[i]*v[j] == i+j){
				ans++;
				//printf("%d %d\n", i, j);
			}
			j+=v[i];
		}
	}

	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}