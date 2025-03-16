#include <bits/stdc++.h>

#define N 1000
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

vector<int> cp[N+1];
int m[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	memset(m, 0, sizeof(m));

	vector<int> a(n+1);


	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		m[a[i]] = i;
	}

	int ans = -1;
	for(int i = 1; i <= n; i++){
		for(int j : cp[a[i]]){
			if(!m[j]) continue;
			ans = max(ans, i + m[j]);
		}
	}

	printf("%d\n", ans);

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= N; j++){
    		if(gcd(i,j) == 1) cp[i].push_back(j);
    	}
    }

	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}