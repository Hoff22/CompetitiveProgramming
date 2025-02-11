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

int flip[N+1];

void solve(){
	int n;
	string a ,b;
	cin >> n >> a >> b;

	a = "1"+a+"1";
	b = "1"+b+"1";

	//cout << a << endl << b << endl;
	int ones = 0;
	int zeros = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == '1') ones++;
		if(a[i] == '0') zeros++;
		if(ones == zeros) flip[i] = 1;
		else flip[i] = 0;
	}

	flip[0] = 1;
	// for(int i = 0; i <= n; i++) cout << flip[i] << ' ';
	// cout << endl;

	int last = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] != b[i]){
			int j;
			for(j = i; j <= n+1; j++){
				if(a[j] == b[j]) break;
			}
			j--;
			//cout << flip[last] << " " << flip[j] << endl;
			if(flip[last] == 0 or flip[j] == 0){
				cout << "NO\n";
				return;
			}

			i = j;
		}
		else last = i;
	}

	cout << "YES\n";
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}