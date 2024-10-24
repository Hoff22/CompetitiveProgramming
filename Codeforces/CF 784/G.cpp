#include <bits/stdc++.h>

#define N 50
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
	cin >> n >> m;

	int arr[N+1][N+1];
	char grid[N+1][N+1];
	char ans[N+1][N+1];


	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			grid[i][j] = c;
		}
	}	


	for(int j = 0; j < m; j++){
		int cur = 0;
		for(int i = 0; i < n; i++){
			if(grid[i][j] == 'o'){
				arr[i][j] = cur;
				cur = 0;
			}
			if(grid[i][j] == '*') cur++;
		}
		arr[n][j] = cur;
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int j = 0; j < m; j++){
		int cur = arr[n][j];
		for(int i = n-1; i >= 0; i--){
			if(grid[i][j] == 'o'){
				cur = arr[i][j];
				ans[i][j] = 'o';
			}
			else if(cur){
				cur--;
				ans[i][j] = '*';
			}
			else{
				ans[i][j] = '.';
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
	cout << endl;

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