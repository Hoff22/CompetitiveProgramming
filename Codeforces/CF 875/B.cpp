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
	cin >> n;
	
	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];


	vector<int> A(2*n+1, 0);
	int cur = 1;
	for(int i = 1; i < n; i++){
		if(a[i] == a[i-1]){
			cur++;
		}
		else{
			A[a[i-1]] = max(A[a[i-1]], cur);
			cur = 1;
		}
	}
	A[a[n-1]] = max(A[a[n-1]], cur);

	vector<int> B(2*n+1, 0);
	cur = 1;
	for(int i = 1; i < n; i++){
		if(b[i] == b[i-1]){
			cur++;
		}
		else{
			B[b[i-1]] = max(B[b[i-1]], cur);
			cur = 1;
		}
	}
	B[b[n-1]] = max(B[b[n-1]], cur);

	int ans = 0;
	for(int i = 0; i <= 2*n; i++){
		ans = max(ans, A[i] + B[i]);
	}

	cout << ans << endl;
}


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