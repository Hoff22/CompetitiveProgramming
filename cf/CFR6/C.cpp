#include <bits/stdc++.h>

#define N 500
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

    int r,c;
    cin >> r >> c;

    if(r == 1 and c == 1){
    	cout << "0\n";
    	return 0;
    }

    int ans[N+1][N+1];

    for(int i = 0; i < r; i++){
    	for(int j = 0; j < c; j++){
    		ans[i][j] = 1;
    	}
    }

    int p = 1;

    if(c == 1){
    	p = 2;
    	for(int i = 0; i < r; i++){
	    	for(int j = 0; j < c; j++){
	    		ans[i][j] *= p;
	    	}
	    	p++;
	    }
    }
    else if(r == 1){
    	p = 2;
    	for(int i = 0; i < c; i++){
	    	for(int j = 0; j < r; j++){
	    		ans[j][i] *= p;
	    	}
	    	p++;
	    }
    }
    else{
	    for(int i = 0; i < r; i++){
	    	for(int j = 0; j < c; j++){
	    		ans[i][j] *= p;
	    	}
	    	p++;
	    }
	 	for(int i = 0; i < c; i++){
	    	for(int j = 0; j < r; j++){
	    		ans[j][i] *= p;
	    	}
	    	p++;
	    }
    }

    for(int i = 0; i < r; i++){
    	for(int j = 0; j < c; j++){
    		cout << ans[i][j] << " ";
    	}
    	cout << endl;
    }

    return 0;

}