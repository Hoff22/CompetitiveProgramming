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

	char c;
	cin >> c;

	int bef, aft;
	bef = 0;
	aft = s.size();
	for(int i = 0; i < s.length(); i++){
		aft--;

		if(s[i] == c){
			if(bef % 2 == 0 and aft % 2 == 0){
				cout << "YES\n";
				return;
			}
		}

		bef--;
	}

	cout << "NO\n";

}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}