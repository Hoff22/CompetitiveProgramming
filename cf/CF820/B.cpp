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
	int n;
	cin >> n;

	string s;

	cin >> s;

	string a = "";


	for(int i = s.size()-1; i>= 0; i--){
		if(s[i] == '0'){
			int x = 'a' + (int)(s[i-1] - '0') + 10*(int)(s[i-2] - '0') - 1;
			a += x;
			i -= 2;
		}
		else{
			a += 'a' + (s[i] - '0' - 1);
		}
	}

	reverse(a.begin(), a.end());

	cout << a << endl;
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