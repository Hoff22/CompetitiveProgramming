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
string s;
int DP[101][101][5005];

int dp(int i, int ones_left, int oz){
	int zero_left = (s.size() - i) - ones_left;
	
	if(i == s.size()){
		if((ones_left+zero_left) == 0 and oz == 2500) return 0;
		return INF;
	}

	if(DP[i][ones_left][oz] != -1) return DP[i][ones_left][oz];

	int r = N;

	if(ones_left){
		r = min(r, dp(i+1, ones_left-1, oz+zero_left) + (s[i] == '0')); // botar 1
	}
	if(zero_left){
		r = min(r, dp(i+1, ones_left, oz-ones_left) + (s[i] == '1')); // botar 0
	}

	return DP[i][ones_left][oz] = r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    cin >> s;

	int one, zero;
	one = zero = 0;
	for(int  i =0; i < s.size(); i++){
		if(s[i] == '1') one++;
		else zero++;
	}	

	memset(DP, -1, sizeof(DP));
	cout << dp(0,one,2500)/2 << endl;

    return 0;

}