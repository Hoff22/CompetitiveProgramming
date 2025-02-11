#include <bits/stdc++.h>
#include <bit>

#define N 5000
#define K 15
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int mx_i[N+1][N+1];
int DP[N+1][N+1];

long long rec(int l, int r){

	if(l == r) return 0;

	if(DP[l][r] != -1) return DP[l][r];

	return DP[l][r] = rec(l, mx_i[l][r]-1) + (r - mx_i[l][r]);
}
//293600 KB
//195776 KB
// 1 2 3  4 5 6 7
void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			DP[i][j] = -1;
		}
	}

	for(int i = n; i >= 1; i--){
		mx_i[i][i] = i;
		for(int j = i-1; j >= 1; j--){
			if(a[j] > a[i]){
				mx_i[j][i] = j;
			}
			else{
				mx_i[j][i] = mx_i[j+1][i];
			}
		}
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		stack<pair<int,int>> st;
		st.push({i,i});
		for(int j = i+1; j <= n; j++){
			int left = mx_i[i][j];
			int right = j;
			while(!st.empty() and left <= st.top().se){
				left = min(st.top().fi, left);
				st.pop();
			}

			st.push({left, right});

			mx_i[i][j] = left;

			ans += j-left;
		}
	}

	cout << ans << endl;
}

/*

2 6 13 3 15 5 10 8          16 9 11 18
                 




*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}