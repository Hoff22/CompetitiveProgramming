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

    long long n, m, ans;
    cin >> n >> m;

    vector<long long> li(n);

    
    for(int i = 0; i < n; i++) cin >> li[i];
    long long l = li[0];
    long long r = n+1;
    for(int i = 0; i < n; i++){
        r += li[i];
        l = max(l, li[i]);
    }
    

    ans = r;

    while(l <= r){
        long long mid = l + (r-l)/2;

        long long cnt = 1ll;
        long long cur = li[0];
        for(int i = 1; i < n; i++){
            if(cur + li[i] + 1ll > mid){
                cnt++;
                cur = li[i];
            }
            else{
                cur = cur + li[i] + 1ll;
            }
        }

        //cout << l << " " << r << endl;

        if(cnt <= m){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    cout << ans << endl;

    return 0;

}