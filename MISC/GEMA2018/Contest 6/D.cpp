#include <bits/stdc++.h>

#define N 100000

using namespace std;

int locker[N+1];
int solve[N+1];
int moves[N+1];

int main(){
    
    int n, k, ans = 0;

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++){
        scanf("%d", &locker[i]);
    }

    for(int i = 1; i <= n; i++){
        scanf("%d", &solve[i]);
    }


    int sum = 0;
    int r;
    for(r = 1; r <= n-k+1; r++){
        int l = max(0, r-k);

        sum -= moves[l];

        int move = solve[r]-((locker[r]+sum+10) % 10);

        if(abs(move) > 5){
            move = 10 - abs(((locker[r]+sum+10) % 10) - solve[r]);
            if(((locker[r]+sum+10) % 10) <= 5){
                move = -move;
            }
        }
        
        moves[r] = move;
        sum += moves[r];

        ans += abs(moves[r]);
    }

    for(; r <= n; r++){
        int l = max(0, r-k);
        sum -= moves[l];
        if(((locker[r]+sum+10) % 10) != solve[r]){
            break;
        }
    }

    if(r <= n){
        printf("-1\n");
    }
    else{
        printf("%d\n", ans);
    }

    // for(int i = 0; i <= n-k; i++){
    //     int move = solve[i]-locker[i];

    //     if(abs(move) > 5){
    //         move = 10 - abs(locker[i]-solve[i]);
    //         if(locker[i] <= 5){
    //             move = -move;
    //         }
    //     }

    //     for(int j = 0; j < k; j++){
    //         locker[i+j] = (locker[i+j]+move+10) % 10;
    //     }
        
    //     ans += abs(move);
    // }

    // int it;
    // for(it = 0; it < n; it++){
    //     if(locker[it] != solve[it]){
    //         break;
    //     }
    // }

    // if(it < n){
    //     printf("-1\n");
    // }
    // else{
    //     printf("%d\n", ans);
    // }

    // 1 1 8 8 0 0
    // 0 0 9 9 3 3
    // 1 1 9 9 3 3   +1
    // 1 1 8 8 3 3   +1
    return 0;
}