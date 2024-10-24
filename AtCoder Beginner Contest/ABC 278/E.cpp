#include <bits/stdc++.h>

#define N 300
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

int cnt[N+1][N+1][N+1];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int H, W, G, h, w;
    cin >> H >> W >> G >> h >> w;

    for(int i = 1; i <= H; i++){
    	for(int j = 1; j <= W; j++){
    		int x;
    		cin >> x;

    		for(int n = 1; n <= G; n++){
    			cnt[n][i][j] = cnt[n][i-1][j] + cnt[n][i][j-1] - cnt[n][i-1][j-1] + (n==x);
    		}
    	}
    }

    // for(int n = 1; n <= 5; n++){
    // 	cout << n << ": \n";
    // 	for(int i = 1; i <= H; i++){
	//     	for(int j = 1; j <= W; j++){
	//     		cout << cnt[n][i][j] << " \n"[j == W];
	//     	}
	//     }
    // }

    for(int i = 1; i <= H-h+1; i++){
    	for(int j = 1; j <= W-w+1; j++){
    		// i,j == top left
    		// k,l == bottom right

    		int k = i + h - 1;
    		int l = j + w - 1;

    		int c = 0;
    		//cout << i << " " << j << " " << k << " " << l << " " << ": \n";
    		for(int n = 1; n <= G; n++){
    			//cout << n << ": " << cnt[n][k][l] - cnt[n][i-1][l] - cnt[n][k][j-1] + cnt[n][i-1][j-1] << endl;
    			c += (cnt[n][k][l] - cnt[n][i-1][l] - cnt[n][k][j-1] + cnt[n][i-1][j-1] < cnt[n][H][W]);
    		}

    		cout << c << " \n"[j == W-w+1];
    	}
    }

    return 0;

}