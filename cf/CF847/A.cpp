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

	string p = "31415926535897932384626433832795028841971";
				// 141592653589793238462643383279

	string a;
	cin >> a;

	string s;

	for(int i = 0; i < a.size(); i++){
		if(a[i] != '0'){
			s = a.substr(i, a.size()-i);
			break;
		}
	}

	for(int i = 0; i < s.size(); i++){
		if(s[i] != p[i]){
			cout << i << endl;
			return;
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