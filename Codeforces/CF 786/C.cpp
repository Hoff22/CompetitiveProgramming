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
	string a,b;
	cin >> a >> b;

	int foundA = 0;
	for(char i : b){
		if(i == 'a') foundA = 1;
	}	
	if(foundA and b.size() > 1){
		cout << -1 << endl;
		return;
	}

	if(foundA and b.size() == 1){
		cout << 1 << endl;
		return;
	}

	cout << (1ll<<a.size()) << endl;
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