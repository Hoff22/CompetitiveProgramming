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

int test(int l, int r, vector<int> a){
	

	int m = l + (r - l) / 2;
	int mn = INF;
	int mx = a[r];
	for(int i = l; i <= r; i++){
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	printf("%d %d\n", l, r);
	if(l >= r-1){
		printf("%d\n", mx);
		return mx;
	} 

	int res = -1;
	if((r - l + 1) % 2 == 0){

		if(a[m] == mn or a[m+1] == mn){
			// good
			int lft = test(l, m-1, a);
			int rgt = test(m + 2, r, a);
			if((lft == -1 or rgt == -1) or (lft > rgt)){
				res = max(res, -1);
			}
			else{
				res = max(res, rgt);
			}
		}
		else{
			//bad
			return -1;
		}
	}
	else{
		if(a[m] == mn){
			int lft = test(l, m-1, a);
			int rgt = test(m + 1, r, a);
			if((lft == -1 or rgt == -1) or (lft > rgt)){
				res = max(res, -1);
			}
			else{
				res = max(res, rgt);
			}
		}
	}
	printf("%d\n", res);
	return res;
}

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	vector<int>s = a;
	sort(s.begin(),s.end());

	int good = 1;
	if(a.size() > 1){
		good = test(0, n-1, a);
	}

	if(good) printf("YES\n");
	else printf("NO\n");
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