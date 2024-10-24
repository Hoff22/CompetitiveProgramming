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
    cin >> n;

    for(int i = 0; i < n; i++){
    	long long x;
    	cin >> x;

    	long long l = (x/14) * 14;

    	if(x - l > 6 or x-l == 0 or x < 14){
    		cout << "NO\n";
    	}
    	else{
    		cout << "YES\n";
    	}
    }

    return 0;

}