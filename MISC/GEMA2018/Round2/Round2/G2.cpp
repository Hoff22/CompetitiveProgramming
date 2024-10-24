#include <bits/stdc++.h>

#define N 5000
#define MAX 10000000000
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n, k;
map<int, int> m;

int main(){
    
    long long ans = 1;

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);

        m[x]++;
    }
    while(k){
        map<int,int>::iterator it;
        for(it = m.begin(); it != m.end() and k; ++it){
            
            if(it->second > 0){
                ans = (ans * it->first) % MOD;
                m[it->first]--;
                k--;
            }
        }
    }


    printf("%lld\n", ans);
    
    return 0;
}