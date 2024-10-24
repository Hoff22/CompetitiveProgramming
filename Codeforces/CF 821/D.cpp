#include <bits/stdc++.h>

#define N 5000
#define fi first
#define se second

using namespace std;

long long n, x, y;

vector<int> d;

long long dp[N+1][N+2][2];

long long go(int i, int j, bool jumped){
	if(i == d.size()){
		if(j == -1){
			return 0;
		}
		else{
			return 0x3f3f3f3f3f3f3f3fll;
		}
	}

	if(dp[i][j+1][jumped] != -1) return dp[i][j+1][jumped];

	long long r = 0x3f3f3f3f3f3f3f3fll;

	if(jumped){
		r = min(r, go(i+1, j, false) + x * (d[i] - d[i-1]));
	}
	else{
		if(j == -1){
			r = min(r, go(i+1, i, false));
		}
		else{
			r = min(r, go(i+1, -1, false) + y * (1 + (d[i] - d[j] == 1)));
		}
		r = min(r, go(i+1, j, true));
	}

	return dp[i][j+1][jumped] = r;
}
/*
	13 3 7
0000000000000
0010011101001

*/

void solve(){
    
    string a,b;
    
    cin >> n >> x >> y >> a >> b;

 	for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		dp[i][j][0] = -1;
    		dp[i][j][1] = -1;
    	}
    }

    d.clear();

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) d.push_back(i);
    }
    
    if(d.size() % 2){
        cout << "-1\n";
        return;
    }

	if(d.size() == 0){
        cout << "0\n";
        return;
    }    
    
    cout << go(0, -1, false) << endl;
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