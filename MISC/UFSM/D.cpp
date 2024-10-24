#include <bits/stdc++.h>

#define N 1000000
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

int a[N+1], b[N+1];

void solve(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	long long ans = 0;
	long long of = 0;
	for(int i = n-1; i >= 0; i--){
		a[i] = ((((a[i] + of) % 10) + 10) % 10);

		long long cur;

		if(b[i] > a[i]){
			if(b[i] - a[i] < a[i] + 10 - b[i]){ // vou pra cima
				cur = b[i] - a[i];
			}
			else{ // vou pra baixo
				cur = -(a[i] + 10 - b[i]);
			}
		}
		else{
			if(a[i] - b[i] < (10 - a[i]) + b[i]){ // vou pra baixo
				cur = -(a[i] - b[i]);
			}
			else{	// vou pra cima
				cur = (10 - a[i]) + b[i];
			}
		}


		of += cur;
		ans += abs(cur);
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}