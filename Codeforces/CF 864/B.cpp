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
	int n, k;
	cin >> n >> k;

	vector<vector<int>> a(n, vector<int>(n));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	} 

	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] != a[n-i-1][n-j-1]) cnt++;
		}
	}
	cnt /= 2;

	if(k < cnt){
		cout << "NO" << endl;
	}
	else{
		if((k-cnt) % 2 and n%2 == 0){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
}

/*
4 3
1 0 1 1
1 0 0 0
0 1 0 1
1 1 0 1


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