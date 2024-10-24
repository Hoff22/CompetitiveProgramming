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

	vector<int> divs;

	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			divs.push_back(i);
			divs.push_back(n/i);
		}
	}

	int ans = INF;
	string t;

	for(int d : divs){
		string a = s;
		int cur = 0;
		
		vector<pair<int,char>> cnt(26);

		for(int i = 0; i < 26; i++) cnt[i] = {0, i+'a'};

		for(int i = 0; i < n; i++){
			cnt[a[i]-'a'].fi++;
		}

		sort(cnt.begin(), cnt.end());
		reverse(cnt.begin(), cnt.end());

		for(int i = 0; i < 26; i++){
			cout << cnt[i].fi << " ";
		}
		cout << endl;
		for(int i = 0; i < 26; i++){
			cout << cnt[i].se << " ";
		}
		cout << endl;

		int x = n/d;

		int l = 0;
		int r = 25;
		while(l < r and x){
			cout << d << " " << x << endl;
			if(cnt[l].fi == d){
				cout << cnt[l].se << endl;
				l++;
				x--;
				continue;
			}
			if(cnt[r].fi == d){
				cout << cnt[r].se << endl;
				r--;
				x--;
				continue;
			}

			char supply = cnt[l].se;
			char demand = cnt[r].se;

			for(int i = 0; i < n; i++){
				if(a[i] == supply){
					a[i] = demand;
					break;
				}
			}

			cnt[l].fi--;
			cnt[r].fi++;

			cur++;
		}

		if(cur < ans){
			ans = cur;
			t = a;
		}
	}

	cout << ans << endl;
	cout << t << endl;
}

/*

AAAABBBCD

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