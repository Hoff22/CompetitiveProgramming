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
// 18:28!!
void solve(){
	int n, k;
	cin >> n >> k;

	vector<string> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	set<int> s;
	for(int i = 0; i < n; i++) s.insert(i);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < k; j++){
			if(a[i][j] != a[0][j]) s.erase(i);
		}
	}

	cout << s.size() << endl;

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