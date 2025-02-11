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


void solve(){
	int n, k;
	string s;
	cin >> n >> k;

	cin >> s;

	int l = 0;
	int r = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == '*'){
			l = i;
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(s[i] == '*'){
			r = i;
		}
	}

	int count = 1;
	while(r!=l){
		int nl = l;
		for(int i = l; i <= min(l+k, r); i++){
			if(s[i] == '*'){
				nl = i;
			}
		}
		l = nl;
		count++;
	}
	
	cout << count << endl;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}