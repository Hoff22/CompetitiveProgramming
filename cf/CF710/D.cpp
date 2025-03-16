#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;


void solve() {
    int n;
    scanf("%d", &n);

    map<int,int> freq;

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);

        freq[x]++;
    }
    for(auto i : freq){
        if(i.second > (n - i.second)){
            printf("%d\n", i.second - (n - i.second));
            return;
        }    
    }

    printf("%d\n", (n%2));
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }
}