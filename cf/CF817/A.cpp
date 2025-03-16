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
	int n;
	string s;
	cin >> n >> s;

	set<char> c;
	c.insert('T');
	c.insert('i');
	c.insert('m');
	c.insert('u');
	c.insert('r');

	if(n != 5){
		cout << "NO\n";
		return;
	}

	for(int i = 0; i < n; i++){
		if(c.count(s[i])){
			c.erase(s[i]);
		}
		else{
			cout << "NO\n";
			return;
		}
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