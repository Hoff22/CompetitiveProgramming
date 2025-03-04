#include <bits/stdc++.h>

#define N 100
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

bool check();

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	vector<int> cnt_(n+1);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cnt_[a[i]]++;
	}
/*
	for(int i = 1; i <= n; i++){
		printf("%d ", cnt_[i]);
	}
	printf("\n");
*/

	int k;
	for(k = n; k >= 1; k--){
		bool good = 1;
		//printf("\t%d\n", k);
		vector<int> cnt = cnt_;
		int mn = INF;
		for(int i = 1; i <= n; i++){
			if(cnt[i]) mn = min(i, mn);
		}

		for(int i = k; i >= 1; i--){
			int j;
			for(j = i; j >= 1; j--){
				if(cnt[j] > 0) break;
			}
			
			if(j == 0){
				good = 0;
				break;
			}
			//printf("%d: %d\n",k, j);
			cnt[j]--;
			cnt[mn]--;
		}

		if(good){
			printf("%d\n", k);
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