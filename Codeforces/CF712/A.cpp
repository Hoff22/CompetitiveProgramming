#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int ispal(string s){

	for(int i = 0; i < s.length()/2; i++){
		if(s[i] != s[s.length() - i - 1]){
			return 0;
		}
	}

	return 1;
}

void solve(){
	string s;
	cin >> s;

	if(!ispal(s+"a")){
		cout << "YES\n";
		cout << s+"a" << endl;
	}
	else if(!ispal("a"+s)){
		cout << "YES\n";
		cout << "a"+s << endl;
	}
	else{
		cout << "NO\n";
	}
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}