#include <bits/stdc++.h>

#define N 5000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)


using namespace std;

int n, m;
int rows[16][10000];
int pos[16][16];
int finals[16][16];
int dp[16][(1<<16)];

int ksolve(int i, int j, bool last){
    int k = INF;
    if(last){
        for(int p = 0; p < m-1; p++){
            k = min(abs(rows[i][p] - rows[j][p+1]), k);
        }
    }
    else{
        for(int p = 0; p < m; p++){
            k = min(abs(rows[i][p] - rows[j][p]), k);
        }
    }
    return k;
}

void printb(int a){
    for(int i = 0; i < n; i++){
        if((a>>i)&1)printf("1");
        else printf("0");
    }
    printf("\n");
}

int f;
int solve(int i, int used){
    // printf("\t%d ", i);
    // printb(used);

    if(used == (1<<n)-1){
        // printf("\t\t%d %d r: %d\n",i,f, finals[i][f]);
        return finals[i][f];
    } // (2^17)-1

    if(dp[i][used] != -1) return dp[i][used];

    int k = 0;
    for(int j = 0; j < n; j++){
        if((used >> j) & 1) continue;
        // printf("\t%d\n",pos[i][j]);
        k = max(k, min(solve( j, used + (1<<j) ) , pos[i][j]) );
    }
    return dp[i][used] = k;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &n, &m);


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &rows[i][j]);
        }
    }
    
    if(n == 1){
        int k = INF;
        for(int p = 0; p < m-1; p++){
            k = min(abs(rows[0][p] - rows[0][p+1]), k);
        }
        printf("%d\n", k);
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            pos[i][j] = ksolve(i, j, 0);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            finals[i][j] = ksolve(i, j, 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        memset(dp, -1, sizeof(dp));
        f = i;
        // printf("f: %d", f);
       // printf(" : %d\n", solve(f,(1<<f)));
        ans = max(ans, solve(f, (1<<f)));
    }

    printf("%d\n", ans);

    return 0;
}

/*

    


*/