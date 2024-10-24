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

	bool good = 0;
	for(int i = 0; i < s.size(); i++){
		if((s[i] - '0') % 2 == 0) good = 1;
	}

	if(!good) printf("-1\n");
	else{
		if((s[s.size()-1] - '0') % 2 == 0) printf("0\n");
		else if((s[0] - '0') % 2 == 0) printf("1\n");
		else printf("2\n");
	}
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