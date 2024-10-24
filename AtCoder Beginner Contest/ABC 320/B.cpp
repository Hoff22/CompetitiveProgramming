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


int pal(string s){
	for(int i = 0; i < s.size()/2; i++){
		if(s[i] != s[s.size()-i-1]) return 0;
	}
	return s.size();
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s;
    cin >> s;

    int ans = 0;
    for(int l = 0; l < s.size(); l++){
    	for(int r = s.size()-1; r >= l; r--){
    		ans = max(ans, pal(s.substr(l,(r-l+1))));
    	}
    }

    cout << ans << endl;

    return 0;

}