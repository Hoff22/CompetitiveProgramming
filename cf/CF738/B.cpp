#include <bits/stdc++.h>

#define N 100
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

char str[N+1];

string ans;

int dp[N+1][2];
bool seen[N+1][2];
int n;

int go(int i, int last){
	if(i == n) return 0;

	if(seen[i][last]) return dp[i][last];
	seen[i][last] = true;

	if(str[i] == '?'){
		return dp[i][last] = min((last == 0 and i > 0) + go(i+1, 0), (last == 1 and i > 0) + go(i+1, 1));
	}

	return dp[i][last] = (last == (str[i] == 'B') and i > 0) + go(i+1, (str[i] == 'B'));
}

void rec(int i, int last){
	if(i == n) return;

	if(str[i] == '?'){
		if((last == 0 and i > 0) + go(i+1, 0) <= (last == 1 and i > 0) + go(i+1, 1)){
			ans += "R";
			rec(i+1, 0);
		}
		else{
			ans += "B";	
			rec(i+1, 1);
		} 
		return;
	}

	ans += str[i];
	rec(i+1, (str[i] == 'B'));
}

void solve(){
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> str[i];
	}

	memset(seen, 0, sizeof(seen));

	ans = "";
	rec(0,0);

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

/*
????R?????
BRBRRBRBRB
RBRBRBRBRB
*/