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
	
    string s;
    cin >> s;

    int c[4] = {0,0,0,0};
    for(int i = 0; i < s.size(); i++){
    	c[0] += (s[i] == 'T');
    	c[1] += (s[i] == 'P');
    	c[2] += (s[i] == 'U');
    	c[3] += (s[i] == 'A');
    }

    cout << min({c[0], c[1], c[2] + c[3]}) << endl;

    return 0;

}