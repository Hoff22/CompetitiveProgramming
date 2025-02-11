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

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> v(n+1);
	set<int> colors;
	vector<bool> used(n+1, 0);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		colors.insert(v[i]);
	}

	if(colors.size() <= 1){
		printf("NO\n");
		return;
	}

	printf("YES\n");
	used[1] = true;
	for(int i = 2; i <= n; i++){
		if(v[1] != v[i]){
			printf("%d %d\n", 1, i);
			used[i] = true;
		}
	}
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			for(int j = 1; j <= n; j++){
				if(v[i] != v[j]){
					printf("%d %d\n", i, j);
					used[i] = true;
					break;
				}
			}
		}
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