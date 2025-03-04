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
	string a, b;
	cin >> a >> b;

	if(a[0] == b[0]){
		cout << "YES\n";
		cout << a[0] << "*" << endl;
		return;
	}
	if(a[a.size()-1] == b[b.size()-1]){
		cout << "YES\n";
		cout << "*" << a[a.size()-1] << endl;
		return;
	}

	for(int i = 0; i < a.size()-1; i++){
		for(int j = 0; j < b.size()-1; j++){
			if(a[i] == b[j] and a[i+1] == b[j+1]){
				cout << "YES\n";
				cout << "*" << a[i] << a[i+1] << "*" << endl;
				return;
			}
		}
	}

	cout << "NO\n";
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