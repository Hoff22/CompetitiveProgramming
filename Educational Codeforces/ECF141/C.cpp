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
	int n, m;
	scanf("%d %d", &n, &m);

	vector<long long> a(n);
	vector<pair<long long, int>> t(n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		t[i] = {a[i], i};
	}

	sort(t.begin(), t.end());

	int l = 1;
	int r = n+1;
	int ans = n+1;

	while(l <= r){
		int md = l + (r - l) / 2;

		if(md == n+1){
			ans = md;
			break;
		}

		int enemy_index = n-md;

		int k = 0;
		long long sum = 0;
		int saw = 0;
		for(int i = 0; i < n and sum <= m; i++){
			sum += t[i].fi;
			if(sum > m) break;
			if(t[i].se == enemy_index) saw = 1;
			k++;
		}

		if(!saw){
			if(k >= n-md+1){ // go left
				ans = md;
				r = md-1;
				continue;
			}
			else{
				if(a[enemy_index] > m){
					l = md+1;
					continue;
				}
				k = 1;
				sum = a[enemy_index];
				for(int i = 0; i < n and sum <= m; i++){
					sum += t[i].fi;
					if(sum > m) break;
					k++;
				}
			}
		}

		if(k >= n-md){ // go left
			ans = md;
			r = md-1;
		}
		else{ // go right
			l = md+1;
		}		
	}

	printf("%d\n", ans);

}

/*

6

1 1 2 2 2 

0 1 2 3|5 : 4 -> 2nd

0 1 2 3 4 : 3 -> 2nd

0 1 2 4|4 : 4 -> 1ft


1 2 3 4 5 6

0 1 2|4 5 6

0 1 3|3 5 6


2

0 0 2 3

0 1 2|4 : 3

0 2 2|4 : 2


*/

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