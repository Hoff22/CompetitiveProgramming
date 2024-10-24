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

    int n, m;
    cin >> n >> m;

    vector<int> ans(m,0);

    int k; cin >> k;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        ans[x-1] = 1;
    }

    vector<vector<int>> s(n, vector<int>());

    for(int i = 0; i < n; i++){
        int p; cin >> p;
        for(int j = 0; j < p; j++){
            int x; cin >> x;
            s[i].push_back(x-1);
        }
    } 

    int cnt = 0;
    vector<int> cur(m,0);
    for(int i = 0; i < n*2; i++){
        cnt++;

        int sw = (i%n);

        for(int p : s[sw]) cur[p] ^= 1;

        if(cur == ans){
            cout << cnt << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;

}