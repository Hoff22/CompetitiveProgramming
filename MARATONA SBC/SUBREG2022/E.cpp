#include <bits/stdc++.h>

#define N 1000001
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

    vector<int> a(N+1, 0);

    int ans = 0;
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	a[x]++;
    	if(a[x+1] == 0){
    		ans++;
    	}
    	else{
    		a[x+1]--;
    	}
    }

    cout << ans << endl;

    return 0;

}