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
    string a, b;
    cin >> n >> a >> b;

    vector<long long> cnt(n+1, 0);
    long long cur = 1;
    for(int i = 0; i < n; i++){
    	if(a[i] == b[i]) cur++;
    	else{
    		cnt[i] = cur;
    		cur = 1;
    	}
    }

    long long ans = 0;

    for(int i = 0; i < n; i++){
    	if(a[i] < b[i]){
    		ans += 1ll * (n-i) * cnt[i];
    	}
    }

    cout << ans << endl;

    return 0;

}