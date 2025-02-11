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

bool isPal(string& s){
	for(int i = 0; i < s.size()/2; i++){
		if(s[i] != s[s.size()-i-1]) return 0;
	}
	return 1;
}

void solve(){
	int n;

	cin >> n;
	map<string, int> s;

	for(int i = 0; i < 2*n-2; i++){
		string x;
		cin >> x;
		s[x]++;
	}

	for(auto a : s){
		string x = a.fi;
		string t = x;
		reverse(t.begin(), t.end());
		
		if(s[t] <= 0+(isPal(x))){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

/*

i io i oi

ioi

a b

ababa

a
ab
aba
abab
a
ba
aba
baba

*/

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