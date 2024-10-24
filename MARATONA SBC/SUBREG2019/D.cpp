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

    string a, b;
    cin >> a >> b;

    int ans = 0;
    for(int i = 0; i < a.size()-b.size()+1; i++){
    	int good = 1;
    	for(int j = 0; j < b.size(); j++){
    		if(b[j] == a[i+j]){
    			good = 0;
    			break;
    		} 
    	}
		ans += good;
    }

    cout << ans << endl;

    return 0;

}