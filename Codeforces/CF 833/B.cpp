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

	long long ans = 0;
	for(int i = 0; i < n; i++){
		int cnt[10];
		memset(cnt, 0, sizeof(cnt));
		for(int c = 0; c < 100; c++){
			if(i+c >= n) break;
			cnt[s[i+c] - '0']++;

			int mx = 0;
			int d = 0;
			for(int j = 0; j < 10; j++){
				if(cnt[j]) d++;

				mx = max(mx, cnt[j]);
			}

			if(d >= mx) ans++;
		}

	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin >> p;
	
	while(p--){
		solve();
	}
    return 0;

}