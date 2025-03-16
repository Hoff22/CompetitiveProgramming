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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	scanf("%d", &n);

	vector<int> tin(n+1, 0);

	for(int i = 1; i < n; i++){
		int u, v;

		scanf("%d %d", &u, &v);

		tin[u]++;
		tin[v]++;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(tin[i] == 1)ans++;
	}

	printf("%d\n", (ans+1)/2);

    return 0;

}