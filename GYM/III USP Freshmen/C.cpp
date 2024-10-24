#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

struct plate{
    int x, y, r;
};

int n;
int a[N+1][N+1];

int main(){

    cin >> n;

    char q;
    int x, y, r;

    memset(a, -1, sizeof(a));
    while(n--){
        cin >> q >> x >> y >> r;

        int ok = true;
        if(q == 'A'){
            for(int i = 0; i <= N; i++){
                for(int j = 0; j <= N; j++){
                    if(a[i][j] != -1){
                        plate other = {i, j, a[i][j]};

                        double dist = sqrt((other.x - x)*(other.x - x) + (other.y - y)*(other.y - y));

                        //printf("%lf %d", dist, other.r + r);
                        if(dist < r + other.r){
                            ok = false;
                        }
                    }
                }
            }

            if(ok){
                a[x][y] = r;
            }
        }
        else if(q == 'R'){
            if(a[x][y] != r){
                ok = false;
            }
            else{
                a[x][y] = -1;
            }
        }

        if(ok){
            printf("Ok\n");
        }
        else{
            printf("No\n");
        }
    }
    

    return 0;

}