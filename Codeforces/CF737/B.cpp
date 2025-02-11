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
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	sort(b.begin(), b.end());

	int cnt = 1;

	for(int i = 0; i < n-1; i++){
		if(*upper_bound(b.begin(), b.end(), a[i]) != a[i+1]){
			cnt++;
		}
	}

	if(cnt <= k) printf("Yes\n");
	else printf("No\n");

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}