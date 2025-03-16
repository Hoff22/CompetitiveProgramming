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

	int a[N+1];
	int b[N+1];

	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);

	vector<int> l;
	vector<int> r;
	for(int i = 1; i <= n; i++){
		while(a[i] != b[i]){
			bool good = 0;
			for(int j = 1; j <= n; j++){
				if(i == j) continue;

				if(a[i] < b[i] and a[j] > b[j]){
					good = 1;
					a[i]++;
					a[j]--;
					l.push_back(j);
					r.push_back(i);
				}
				else if(a[i] > b[i] and a[j] < b[j]){
					good = 1;
					a[i]--;
					a[j]++;
					l.push_back(i);
					r.push_back(j);
				}
			}
			if(!good){
				printf("-1\n");
				return;
			}
		}
	}

	printf("%d\n", (int)l.size());
	for(int i = 0; i < l.size(); i++){
		printf("%d %d\n", l[i], r[i]);
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