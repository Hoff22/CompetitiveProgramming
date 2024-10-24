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

	string s;
	cin >> s;

	int n = s.size();

	string a = "Yes";

	int p = 0;

	if(s[0] == 'Y'){
		p = 0;
	}
	else if(s[0] == 'e'){
		p = 1;
	}
	else if(s[0] == 's'){
		p = 2;
	}
	else{
		cout << "NO\n";
		return;
	}

	for(int i = 0; i < n; i++){
		if(s[i] != a[p]){
			cout << "NO\n";
			return;
		}

		p = (p+1) % 3;
	}

	cout << "YES\n";
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