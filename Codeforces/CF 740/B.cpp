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
	int a,b;
	scanf("%d %d", &a, &b);

	if(a < b) swap(a,b);

	vector<int> ans;

	int s = a+b;
	for(int i = 0; i <= s; i++){
		int k1 = a - s/2;
		int k2 = a - (s+1)/2;
		if(i >= k1 and (i - k1) <= 2 * b and (i - k1) % 2 == 0){
			ans.push_back(i);
		} 
		else if(i >= k2 and (i - k2) <= 2 * b and (i - k2) % 2 == 0){
			ans.push_back(i);
		}
	}
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}