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
	int n, k;

	scanf("%d %d", &n, &k);

	vector<int> v;

	for(int i = 0 ; i < n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	for(int i = 0; i < n; i++){
		if(i >= k){
			printf("%d ", v[i]);
		}
	}

	for(int i = 0; i < min(k, n); i++){
		printf("%d%c", 0, " \n"[i==(min(k, n)-1)]);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}