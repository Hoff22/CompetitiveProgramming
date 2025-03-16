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

int moves[61][2];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    long long n, p ,h;

    cin >> n >> p >> h;
    	
    long long cur = p;
    for(long long i = 1; i < n; i++){
    	if(cur > (1ll<<(n-i))){
    		cur = (1ll<<(n-i+1)) - cur + 1;
    	}

    	if(cur > (1ll<<(n-i-1))){
    		moves[i][1] = 1;
    		moves[i][0] = 0;

    	}
    	else{
    		moves[i][0] = 1;
    		moves[i][1] = 0;
    	}
    }

    // for(int i = 1; i < n; i++){
    // 	cout << "moves[" << i << "][0]: " << moves[i][0] << endl;
    // 	cout << "moves[" << i << "][1]: " << moves[i][1] << endl;
    // 	cout << endl;
    // }

    string ans = "";

    if(h%2 == p%2){
    	ans += 'R';
	    if(h > (1ll<<(n-1))){
	    	cur = 2;
	    	h = (1ll<<(n)) - h + 1; 
	    }
	    else cur = 1;
    }
    else{
    	ans += 'L';
    	if(h > (1ll<<(n-1))){
	    	cur = 1; 
	    	h = (1ll<<(n)) - h + 1; 
	    }
	    else cur = 2;
    }

    int j = 2;
    for(long long i = n-1; i >= 1; i--){
    	//cout << cur << " " << h << endl;
		if(moves[i][cur > (1ll<<(n-i-1))]){
			ans += 'R';
			if(h > (1ll<<(n-j))){
		    	cur = (1ll<<(n-i)) + (1ll<<(n-i)) - cur + 1;
		    	h = (1ll<<(n-j+1)) - h + 1; 
		    }
		    // else cur se mantem
		}
		else{
			ans += 'L';
			if(h > (1ll<<(n-j))){
		    	cur = (1ll<<(n-i)) - cur + 1;
		    	h = (1ll<<(n-j+1)) - h + 1; 
		    }
		    else{
		    	cur += (1ll<<(n-i));
		    }
		}


		j++;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;

}