#include <bits/stdc++.h>

#define N 1000000

using namespace std;

int a[N];

int main(){
    
    int n, jumps = 1;
    scanf("%d", &n);

    for (int j = 0; j < n-1; j++){
        scanf("%d", &a[j]);
    }

    pair<int, int> range = {1, a[0]};
    while(range.second < n-1){

        int best_range = 0;
        for(int i = range.first; i <= range.second; i++){
            best_range = max(i+a[i], best_range);
        }

        range.first = range.second+1;
        range.second = best_range;
        jumps++;
    }


    printf("%d\n", jumps);
    return 0;
}