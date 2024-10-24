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

	vector<int> a(n);
	int mx = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}

	int last = INF;
	for(int i = 0; i < n; i++){
		if(a[i] == mx and last < a[i]){
			printf("%d\n", i+1);
			return;
		}
		if(last == mx and a[i] < last){
			printf("%d\n", i);
			return;
		}
		last = a[i];
	}

	printf("-1\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}