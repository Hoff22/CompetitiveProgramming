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

void solve(){
	int k, n;
	scanf("%d %d", &k, &n);

	int p = 1;
	vector<int> v(k+1,0);
	v[1] = 1;
	for(int i = 2; i <= k; i++){
		if(n - (v[i-1] + p) >= k-i){
			v[i] = v[i-1] + p;
			p++;
		}
		else{
			v[i] = v[i-1] + 1;
		}
	}

	for(int i = 1; i <= k; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

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