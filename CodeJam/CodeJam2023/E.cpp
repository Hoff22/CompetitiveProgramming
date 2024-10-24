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

typedef long long ll;

int DP[2001][3][3];
string s;
vector<int> p;

int dp(int i, int last, int first){
	if(i == p.size()-1){
		if(p[i] == last or p[i] == first) return 1;
		return 0;
	}


	if(DP[i][last][first] != -1) return DP[i][last][first];

	int ans = INF;

	ans = min(ans, dp(i+1, (last+1)%3, first) + ((last+1)%3 != p[i]) );
	ans = min(ans, dp(i+1, (last+2)%3, first) + ((last+2)%3 != p[i]) );

	return DP[i][last][first] = ans;
}

void solve(){
	cin >> s;

	p.clear();

	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'R') p.push_back(0);
		if(s[i] == 'P') p.push_back(1);
		if(s[i] == 'S') p.push_back(2);
	}

	memset(DP, -1, sizeof(DP));

	int ans = INF;
	for(int i = 0; i < 3; i++){
		ans = min(ans, dp(1, i, i) + (p[0] != i));
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;

}