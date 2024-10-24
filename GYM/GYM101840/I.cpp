#include <bits/stdc++.h>
#include <fstream>

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

int cnt[200+1][200+1][2000+1];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ifstream file("important.in");
    if(file.is_open() == false){
        cout << "not open" << endl;
        return 0;
    }

    int t;

    file >> t;

    memset(cnt, 0, sizeof(cnt));

    for(int ts = 1; ts <= t; ts++){
    	int n, m, q;
    	file >> n >> m >> q;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int x; file >> x;
                for(int k = 1; k <= 2000; k++){
                    cnt[i][j][k] = 0;
                }   
                if(i > 1){
                    for(int k = 1; k <= 2000; k++){
                        cnt[i][j][k] += cnt[i-1][j][k];
                    }
                }
                if(j > 1){
                    for(int k = 1; k <= 2000; k++){
                        cnt[i][j][k] += cnt[i][j-1][k];
                    }                    
                }
                if(i > 1 and j > 1){
                    for(int k = 1; k <= 2000; k++){
                        cnt[i][j][k] -= cnt[i-1][j-1][k];
                    }
                }
                cnt[i][j][x]++;
            }
        }

        cout << "Case " << ts << ": " << endl;
        while(q--){
            int i1,j1,i2,j2;

            file >> i1 >> j1 >> i2 >> j2;

            int sz = (i2-i1+1) * (j2-j1+1);
            int cur = 0;
            for(int k = 1; k <= 2000; k++){
                cur += cnt[i2][j2][k] - cnt[i2][j1-1][k] - cnt[i1-1][j2][k] + cnt[i1-1][j1-1][k];
                if(cur > sz/2){
                    cout << k << endl;
                    break; 
                }
            }
        }
    }

    return 0;

}