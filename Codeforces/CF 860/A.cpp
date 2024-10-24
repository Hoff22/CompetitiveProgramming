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

	vector<int> a(n+1);
	vector<int> b(n+1);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}

	int a_mx = 0;
	int b_mx = 0;

	for(int i = 1; i <= n; i++){
		if(b[i] > a[i]) swap(b[i], a[i]);
		a_mx = max(a_mx, a[i]);
		b_mx = max(b_mx, b[i]);
	}

	if(a[n] == a_mx and b[n] == b_mx){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
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