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

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	sort(a.begin(), a.end());

	// 1 4 8 9 10
	// 0   2
	//   1   3
	// 

	vector<int> ans;

	for(int i = 0; i < n/2; i++){
		ans.push_back(a[i]);
		ans.push_back(a[i + (n+1)/2]);
	}
	if(n%2){
		ans.push_back(a[n/2]);
	}

	for(int i = 0; i < n; i++){
		int prev = (i-1+n) % n;
		int next = (i+1+n) % n;

		if(ans[i] < ans[prev] and ans[i] < ans[next]) continue;
		if(ans[i] > ans[prev] and ans[i] > ans[next]) continue;
		
		printf("NO\n");
		return;
	}

	printf("YES\n");

	for(int i = 0; i < n ; i++){
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