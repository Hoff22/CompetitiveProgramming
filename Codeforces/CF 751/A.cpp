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

	int mn = 0;

	for(int i = 0; i < s.size(); i++){
		if(s[i] < s[mn]) mn = i;
	}

	string b = "";
	for(int i = 0; i < s.size(); i++){
		if(i != mn) b += s[i];
	}

	cout << s[mn] << " " << b << endl;

}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}