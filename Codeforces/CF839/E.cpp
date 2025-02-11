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

	vector<int> v(n+1);
	int b = 0;
	int r = 0;
	int tie = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		if(i != v[i] and n-i+1 != v[i]) tie++;
		if(i != v[i]) r++;
		if(n-i+1 != v[i]) b++;
	}

	b = b - (r - tie);
	r = r - (r - tie);

	if(b < 0){
		printf("Second\n");
		return;
	}
	
	if(b >= tie*2){
		printf("First\n");
		return;
	}

	printf("Tie\n");

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