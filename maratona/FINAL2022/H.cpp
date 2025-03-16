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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	


	int n;
	cin >> n;

	vector<string> names(n+1); 
	map<string,int> idx;
	vector<vector<int>> could(n+1, vector<int>(n+1, 1));

	for(int i = 1; i <= n; i++){
		cin >> names[i];
		idx[names[i]] = i;
	}

	int m;
	cin >> m;

	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		
		vector<int> isin(n+1, 0);

		for(int j = 0; j < x; j++){
			string c;
			cin >> c; 
			isin[idx[c]] = 1;
		}

		for(int j = 1; j <= n; j++){
			if(isin[j]){
				for(int p = 1; p < y; p++){
					could[j][p] = 0;
				}
			}
			else{
				could[j][y] = 0;
			}
		}

		// for(int k = 1; k <= n; k++){
		// 	cout << names[k] << ": ";
		// 	for(int j = 1; j <= n; j++){
		// 		cout << could[k][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
	}

	vector<int> used(n+1, 0);
	for(int i = 1; i <= n; i++){
		for(int p = 1; p <= n; p++){
			if(could[i][p] and !used[p]){
				used[p] = i;
				break;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << names[used[i]] << " ";
	}
	cout << endl;
    
	
    return 0;

}