#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	string a[N];
	string b[N];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n-1; i++){
		cin >> b[i];
	}

	vector<char> s;
	for(int k = 0; k < m; k++){
		unordered_map<char,int> w;
		for(int i = 0; i < n; i++){
			w[a[i][k]]++;
		}
		for(int j = 0; j < n-1; j++){
			w[b[j][k]]--;
		}
		for(auto c : w){
			if(c.se > 0) s.push_back(c.fi); 
		}
	}

	for(int i = 0; i < s.size(); i++){
		cout << s[i];
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