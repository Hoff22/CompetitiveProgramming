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
	int a,b;
	cin >> a >> b;

	string s;
	cin >> s;
	// 0?010?0
	for(int i = 0; i < s.length()/2 + (s.length()%2); i++){
		int cmp = (int)s.length() - i - 1;
		
		if(i == cmp){
			if(s[i] == '0') a--;
			if(s[i] == '1') b--;
			continue;
		}
		if(s[i] == '0'){
			if(s[cmp] == '1'){
				break;
			}
			s[cmp] = '0';
			a -= 2;
		}
		if(s[i] == '1'){
			if(s[cmp] == '0'){
				break;
			}
			s[cmp] = '1';
			b -= 2;
		}
		if(s[i] == '?'){
			if(s[cmp] == '0'){
				s[i] = '0';
				a -= 2;
			}
			if(s[cmp] == '1'){
				s[i] = '1';
				b -= 2;
			}
		}
		// cout << "  " << s << endl;
		// cout << a << ' ' << b << endl;
	}

	for(int i = 0; i < s.length(); i++){
		int cmp = (int)s.length() - i - 1;
		if(s[i] == '?'){
			if(a >= b){
				s[i] = s[cmp] = '0';
				a -= !(i == cmp) + 1;
			}
			else{
				s[i] = s[cmp] = '1';
				b -= !(i == cmp) + 1;
			}
		}
	}
	if(b == 0 and a == 0){
		cout << s << endl;
	}
	else{
		cout << -1 << endl;
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