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
	map<char, int> seen;

	for(int i = 0; i < s.size(); i++){
		seen[s[i]]++;
	}

	if(seen.size() > 2){
		cout << 4 << endl;
	}

	if(seen.size() == 2){
		if(seen.begin()->se == 1 or seen.begin()->se == 3){
			cout << 6 << endl;
		}
		else{
			cout << 4 << endl;
		}
	}

	if(seen.size() == 1){
		cout << -1 << endl;
	}

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

// 1 2 2 1

// 1 2 3 1