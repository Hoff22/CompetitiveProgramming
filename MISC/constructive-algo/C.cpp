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

    int v = 1;
    int h = 1;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == '0'){
    		if(v == 1) cout << "3 1\n";
    		else cout << "1 1\n";
    		v *= -1;
    	}
    	else{
    		if(h == 1) cout << "1 3\n";
    		else cout << "1 1\n";
    		h *= -1;
    	}
    }


    return 0;

}