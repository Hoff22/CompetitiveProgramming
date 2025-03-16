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
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	int mxW = 0;
	int mnW = 0;
	int mxH = 0;
	int mnH = 0;

	int curW = 0;
	int curH = 0;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'R'){
			if((curW+1) - mnW >= m) break;
			curW++;
		}
		if(s[i] == 'L'){
			if(mxW - (curW-1) >= m) break;
			curW--;
		}
		if(s[i] == 'U'){
			if(mxH - (curH-1) >= n) break;
			curH--;
		}
		if(s[i] == 'D'){
			if((curH+1) - mnH >= n) break;
			curH++;
		}
		mxW = max(mxW, curW);
		mnW = min(mnW, curW);
		mxH = max(mxH, curH);
		mnH = min(mnH, curH);
	}

	printf("%d %d\n", 1 - mnH, 1 - mnW);

}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}