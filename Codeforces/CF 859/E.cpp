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

int a[N+1];

bool comp(int _a, int _b){
	return a[_a] < a[_b];
}

void solve(){
	int n;
    cin >> n;

    vector<int> idx(n);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	idx[i] = i;
    }

    sort(idx.begin(), idx.end(), comp);

    int l = 0;
    int r = n-1;

    while(l < r){
    	int m = (l+r) / 2;
    	//cout << "m: " << m << endl;

    	int aL = 0;
    	int eL = 0;
    	
    	cout << "? " << (m-l+1) << " ";
    	for(int i = l; i <= m; i++){
    		cout << idx[i]+1 << " ";
    		eL += a[idx[i]];
    	}
    	cout << endl;
    	cout.flush();
    	cin >> aL;

    	if(aL == eL){ // leftside was right
    		l = m+1;
    	}
    	else{ // leftside was wrong
    		r = m;
    	}
    }

    cout << "! " << idx[l]+1 << endl;
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