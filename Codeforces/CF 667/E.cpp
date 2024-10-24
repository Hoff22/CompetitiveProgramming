#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int first[N+1];
int second[N+1];
int bestF[N+1];

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> x(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%*d");
	}

	sort(x.begin()+1, x.end());

	bestF[0] = 0;
	for(int r = 1; r <= n; r++){
		int l = (int)(lower_bound(x.begin() + 1, x.begin() + r + 1, x[r] - k) - x.begin());
	
		first[r] = r - l + 1;
		bestF[r] = max(first[r], bestF[r - 1]);

		second[r] = first[r];
		if(r - first[r] >= 1){
			second[r] += bestF[r - first[r]];
		}
	}

	printf("%d\n", *max_element(second + 1, second + n + 1));

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}