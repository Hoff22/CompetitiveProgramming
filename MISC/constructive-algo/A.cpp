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

    int j = 1;
    for(int i = 0; i < n; i++){
    	if(j==1) cout << 'a';
    	else cout << 'b';
    	if(i%2==0) j*=-1;
    }
    cout << endl;

    return 0;

}