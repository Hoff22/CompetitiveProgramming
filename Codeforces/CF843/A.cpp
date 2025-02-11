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

	string n;

	cin >> n;

	string a, b, c;
	

	if(n[0] < n[1]){
		cout << n[0] << " " << n.substr(1, n.size()-2) << " " << n[n.size()-1] << endl;
	}
	else{
		cout << n[0] << " " << n[1] << " " << n.substr(2, n.size()-2) << endl;

	}
	
	


}

/*

	a b a

	b a b



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