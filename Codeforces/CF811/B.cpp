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

	vector<int> cnt(n+1);

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = n-1; i >= 0; i--){
		cnt[a[i]]++;
		if(cnt[a[i]] > 1){
			printf("%d\n", i+1);
			return;
		}
	}

	printf("0\n");
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