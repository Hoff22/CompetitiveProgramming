#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

void solve(){
	int q;
	cin >> q;

	int f = 0;
	int l = 0;
	int rot = 0;

	string ans = "";
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;

		if(i == 0) f = x;

		if(rot){
			if(x <= f and x >= l){
				l = x;
				ans.push_back('1');
			}
			else{
				ans.push_back('0');
			}
		}
		else{
			if(x >= l){
				l = x;
				ans.push_back('1');
			}
			else if(x <= f){
				l = x;
				rot = 1;
				ans.push_back('1');
			}
			else{
				ans.push_back('0');
			}
		}
	}

	cout << ans << endl;
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