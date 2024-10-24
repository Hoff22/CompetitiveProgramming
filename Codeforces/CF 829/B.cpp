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
	int n;
	scanf("%d", &n);

	vector<int> ans(n);

	int p = 1;
	for(int i = 1; i < n; i+=2){
		ans[i] = p;
		p++;
	}

	for(int i = 0; i < n; i+=2){
		ans[i] = p;
		p++;
	}

	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
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