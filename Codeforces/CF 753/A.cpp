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
	string a;
	cin >> a;

	string s;
	cin >> s;

	int ans = 0;
	int last = -1;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < a.size(); j++){
			if(s[i] == a[j]){
				if(last == -1){
					last = j;		
				}
				else{
					ans += abs(last - j);
					last = j;
				}
				break;
			}
		}
	}

	cout << ans << endl;
}

int main(){
	
	int t;
	cin >> t;

	while(t--){
		solve();
	}

    return 0;

}