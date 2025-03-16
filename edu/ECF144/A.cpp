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

string comp;

void solve(){
	string s;
	int n;
	cin >> n >> s;



	if(n == 1){
		cout << "YES\n";
		return;
	}

	for(int i = 0; i < comp.size(); i++){
		int j;
		int t;
		for(j = 0, t = i; j < n; j++,t++){
			if(s[j] != comp[t]) break;
		}
		if(j >= n){
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";

}

/*

FBFBFBFB
  


*/


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	comp = "";
	int k = 1;
	while(comp.size() < 100){
		if(k % 3 ==0) comp += 'F';
		if(k % 5 == 0) comp += 'B';
		k++;
	}

	while(t--){
		solve();
	}
    return 0;

}