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
// 18:56!!!

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n, q;
    cin >> n >> q;

    vector<ll> a(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<ll> b(n+1, 0);

    ll cnt = 0;
    int fs = 0;
    for(int i = 1; i <= n; i++){
        b[i] = 1;
        if(a[i] <= a[i-1]){
            cnt++;
            if(cnt == 1){
                fs = i;
            }
            if(cnt > 1){
                b[i] = 0;
                b[fs] = 0;
            }
        }
        else{
            b[i-1] = 1;
            b[i] = 1;
            cnt = 0;
        }
    }

    b[n] = 1;

    vector<ll> acc(n+1, 0);

    for(int i = 1; i <= n; i++){
        acc[i] = acc[i-1] + b[i];
    }

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;

        cout << acc[r] - acc[l-1] + (b[l] == 0) + (b[r] == 0 and r!=l) << endl;
    }

    return 0;

}