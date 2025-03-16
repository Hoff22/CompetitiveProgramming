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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'a') cur++;
    	else{
    		if(cur > 1) ans += cur;
    		cur = 0;
    	}
    }
	if(cur > 1) ans += cur;

	cout << ans << endl;

    return 0;

}