#include <bits/stdc++.h>

#define N 300000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)


using namespace std;

int a[N+1];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //memset(dp, -1, sizeof(dp));

    int n,k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int l = 1;
    int r = n;
    pair<int,int> ans = {0,0};

    while(l <= r){
        int m = (l+r) / 2;

        int mn = INF;
        pair<int,int> best;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            cnt += (a[i] == 0);
        }
        for(int i = 0; i + m - 1 < n; i++){
            if(mn > cnt){
                best = {i, i+m-1};
                mn = cnt;
            }
            if(i+m < n){
                if(a[i] == 0) cnt--;
                if(a[i+m] == 0) cnt++;
            }
        }

        if(mn <= k){
            ans = best;
            l = m+1;
        }
        else{
            r = m-1;
        }

    }

    //printf("%d %d\n", ans.fi, ans.se);
    if(ans.fi == ans.se and a[ans.fi] == 0 and k == 0){
        printf("0\n");
        for(int i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        return 0;
    }

    for(int i = ans.fi; i <= ans.se ; i++){
        a[i] = 1;
    }

    printf("%d\n", ans.se-ans.fi+1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

/*

    


*/