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

	if(s == "()"){
		cout << "NO" << endl;
		return;
	}

	int type = 0;

	for(int i = 0; i < s.size()-1; i++){
		if(s[i] == s[i+1]) type = 1;
	}

	cout << "YES" << endl;
	if(type){
		for(int i = 0; i < s.size()*2; i+=2){
			cout << "()";
		}
		cout << endl;
	}
	else{
		for(int i = 0; i < s.size(); i++){
			cout << "(";
		}
		for(int i = 0; i < s.size(); i++){
			cout << ")";
		}
		cout << endl;
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