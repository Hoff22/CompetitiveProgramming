#include <bits/stdc++.h>

#define N 200000
#define MAX 2000000
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
	int n;
	scanf("%d", &n);

	vector<int> v;

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	int ans = 0;
	int cur = 0;
	for(int i = 0; i < n; i++){
		int eq = 0;
		map<int,int> divs;
		for(int j = 0; j < n; j++){
			if(v[j] == v[i]) eq++;
			else if(v[j] > v[i]){
				int dif = v[j] - v[i];

				for(int k = 1; k * k <= dif; k++){
					if(dif % k == 0){
						divs[k]++;
						if(k != dif/k)divs[dif/k]++;
					}
				}
			}

		}
		for(auto k : divs){
			//printf("%d %d %d\n", k.first, k.second, v[i]);
			if(k.second + eq >= n/2){
				cur = k.first;
			}
		}
		if(eq >= n/2){
			printf("-1\n");
			return;
		}
		ans = max(ans, cur);
	}

	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}