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
	int n, h_, m_;
	scanf("%d %d %d", &n, &h_, &m_);

	int x = h_*60 + m_;

	vector<int> a(n);

	for(int i = 0; i < n; i++){
		int h, m;
		scanf("%d %d", &h, &m);

		a[i] = h*60 + m;
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < n; i++){
		if(a[i] >= x){
			int y = a[i] - x;
			printf("%d %d\n", y/60, y%60);
			return;
		}
	}

	int y = ((23*60 + 60) - x) + a[0];
	printf("%d %d\n", y/60, y%60);
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