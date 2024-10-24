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


vector<pair<int,int>> solve(int n, int k, vector<int> a){
    vector<int> cnt(n,0);
    vector<int> used(k, 0);
    vector<pair<int,int>> ans(k);

    for(int i = 0; i < k; i++){
        if(a[i] == -1) a[i] = 1;
        ans[i] = {x, 0};
        cnt[x]++;
    }

    int free = k;
    while(free > 0){
        
        int big = 1;
        int small = 1;
        int d = k/n;

        for(int i = 1; i <= n; i++){
            if(!cnt[i]) continue;
            if(cnt[i] > cnt[big] or cnt[big] == 0){
                big = i;
            }
        }
        for(int i = 1; i <= n; i++){
            if(!cnt[i]) continue;
            if(cnt[i] < cnt[small] or cnt[small] == 0){
                small = i;
            }
        }

        for(int i = 0; i < k; i++){
            if(used[i] == 0 and a[i] == small){
                used[i] = 1;
                cnt[small]--;
                ans[i].se = big;
                d--;
                free--;
            }
        }

        for(int i = 0; i < k and d; i++){
            if(used[i] == 0 and a[i] == big){
                used[i] = 1;
                cnt[big]--;
                ans[i].se = small;
                d--;
                free--;
            }
        }
    }

    return ans;
}
    
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    
    return 0;
}