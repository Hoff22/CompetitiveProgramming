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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    scanf("%d", &n);

    vector<long long> v;
    vector<long long> v1;

    for(int i = 0; i < n; i++){
        long long x, y;
        scanf("%lld %lld", &x, &y);
        
        v1.push_back(x-y);
        v.push_back(x+y);
    }

    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());

    printf("%lld\n", max(v.back() - v.front(), v1.back() - v1.front()));

    return 0;

}