#include <bits/stdc++.h>

#define N 300000
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
	int n;
	string s;

	cin >> n >> s;

	if(s[0] == '0' or s[n-1] == '0'){
		cout << "NO\n";
		return;
	}

	int ones = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1') ones++;
	}
	if(ones%2){
		cout << "NO\n";
		return;
	}

	string a,b;
	for(int i = 0; i < n; i++){
		a += ".";
		b += ".";
	}
	int k = 0;
	int last = 1;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			if(k < ones/2) {
				a[i] = '(';
				b[i] = '(';
				k++;
			}
			else {
				a[i] = ')';
				b[i] = ')';
			}
		}
		else{
			if(last == -1){
				last *= -1;
				a[i] = '(';
				b[i] = ')';
			}
			else{
				last *= -1;
				a[i] = ')';
				b[i] = '(';
			}
		}
	}

	cout << "YES\n";
	cout << a << endl << b << endl;

}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
	return 0;

}