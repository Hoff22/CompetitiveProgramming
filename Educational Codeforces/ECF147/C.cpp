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
	string s;
	cin >> s;

	int ans = INF;

	for(char c = 'a'; c <= 'z'; c++){
		vector<int> a;
		int cur = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == c){
				a.push_back(cur);
				cur = 0;
			}
			else{
				cur++;
			}
		}
		a.push_back(cur);
		// cout << c << endl;
		int cur_ans = 0;
		for(int i : a){
			int cnt = 0;
			// cout << i << ": ";
			while(i){
				cnt++;
				i>>=1;
			}
			// cout << cnt << " ";
			cur_ans = max(cur_ans, cnt);
		}
		// cout << endl;

		// if(ans > cur_ans){
		// 	cout << "choose " << c << endl;
		// }
		ans = min(ans, cur_ans);
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