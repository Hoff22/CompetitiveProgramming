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

int a[10001][101];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int w, s, x, y;
    cin >> w >> s >> x >> y;


    for(int i = 0; i < w; i++){
	    for(int j = 0; j < x; j++){
	    	cin >> a[i][j];
	    }
    }

    vector<int> mx(x, 0);

    for(int i = 0; i < s; i++){
    	for(int j = 0; j < x; j++){
    		int Y; cin >> Y;
    		mx[j] = max(mx[j], Y);
    	}
    }

    for(int i = 0; i < w; i++){
    	for(int j = 0; j < x; j++){
    		cout << min(a[i][j], y-mx[j]) << " ";
    	}
    	cout << endl;
    }

    return 0;

}