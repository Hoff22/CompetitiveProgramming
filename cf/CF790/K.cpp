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
string s;

void solve(){
	cin >> s;

	int z = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') z++;
	}

	int l = 0;
	r = z;
	while(l < r){
		int m = l + (r - l) / 2;

		if(check(m)){
			r = m;			
		}
		else{
			l = m+1;
		}
	}

	cout << l << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >>t;
	
	while(t--){
		solve();
	}
    return 0;

}