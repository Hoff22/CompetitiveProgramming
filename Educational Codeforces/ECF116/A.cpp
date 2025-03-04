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

	int n = (int)s.size();

	if(s[0] != s[n-1]){
		if(s[0] == 'a'){
			s[n-1] = 'a';
		}
		else{
			s[n-1] = 'b';
		}
	}

	cout << s << endl;

}

int main(){
	
	int t;
	cin >> t;	
	while(t--){
		solve();
	}
    return 0;

}