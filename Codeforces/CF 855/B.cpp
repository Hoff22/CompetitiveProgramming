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

	int n, k;
	string s;
	cin >> n >> k >> s;

	int up[26];
	int low[26];

	memset(up, 0 ,sizeof(up));
	memset(low, 0 ,sizeof(low));

	for(int i = 0; i < n; i++){
		if(s[i] >= 'A' and s[i] <= 'Z'){
			up[s[i]-'A']++;
		}
		else{
			low[s[i]-'a']++;
		}
	}

	long long ans = 0;

	for(int i = 0; i < 26; i++){
		ans += min(low[i], up[i]);
		low[i] = (abs(low[i]-up[i]) / 2);
	}

	for(int i = 1; i <= k; i++){
		for(int j = 0; j < 26; j++){
			if(low[j] > 0){
				ans++;
				low[j]--;
				break;
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