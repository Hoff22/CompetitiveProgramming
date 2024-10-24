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

void solve()
{
    int n, k;
    cin >> n >> k;

    int idx = -1;
    for(int i = 0; i <= n; i++){
    	int l = i;
    	int r = n-i;
    	if((l*(l-1))/2 + (r*(r-1))/2 == k){
    		idx = i;
    		break;
    	}
    }

    if (idx == -1){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for(int i = 0; i < idx; i++) cout << "1 ";
    for(int i = 0; i < n-idx; i++) cout << "-1 ";
    cout << endl;
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