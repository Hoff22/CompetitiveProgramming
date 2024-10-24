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

pair<int,int> a[N+1];
int n;

int check(int p){
	for(int i = 0; i < n; i++){
		if(p < a[i].fi) return 0;
		p += a[i].se;
	}
	return 1;
}

void solve(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int k;
		scanf(" %d", &k);
		int mx = 0;
		for(int j = 0; j < k; j++){
			int p;
			scanf("%d", &p);
			mx = max(mx, p-j);
		}

		a[i] = {mx, k};
	}

	sort(a, a+n);

	int l = 0;
	int r = MAX;
	while(l < r){
		int m = l + (r - l)/2;

		if(check(m)){
			r = m;
		}
		else{
			l = m+1;
		}
	}

	printf("%d\n", l+1);

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}