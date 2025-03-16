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
	string s;
	cin >> n >> s;

	int a[26];
	int b[26];

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	int fa = 0;
	int fb = 0;

	for(int i = 0 ; i < n; i++){
		if(b[s[i]-'a'] == 0) fb++;
		b[s[i]-'a']++;
	}

	int mx = 0;

	for(int i = 0; i < n; i++){
		if(a[s[i]-'a'] == 0) fa++;
		a[s[i]-'a']++;
		b[s[i]-'a']--;
		if(b[s[i]-'a'] == 0) fb--;

		if(fa+fb > mx){
			mx = fa+fb;
		}
	}

	cout << mx << endl;

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