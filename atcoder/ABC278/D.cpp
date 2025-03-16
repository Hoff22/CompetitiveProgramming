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
	
    int n, q;

    cin >> n;

    vector<pair<long long,int>> a(n+1);

    for(int i = 1; i <= n; i++){
    	cin >> a[i].fi;
    	a[i].se = 0;
    }

    cin >> q;

    long long v = 0;
    int lt = 0;

    for(int i = 1; i <= q; i++){
    	int t;
    	cin >> t;

    	if(t == 1){
    		int x;
    		cin >> x;
    		v = x;
    		lt = i;
    	}
    	else if(t == 2){
    		int j, x;
    		cin >> j >> x;
    		if(a[j].se < lt){
    			a[j].first = v + x;
    		}
    		else{
    			a[j].first += x;
    		}
    		a[j].se = i;
    	}
    	else{
    		int j;
    		cin >> j;
    		if(a[j].se < lt){
    			a[j].first = v;
    		}
    		a[j].se = i;

    		cout << a[j].fi << endl;
    	}
    }

    return 0;

}