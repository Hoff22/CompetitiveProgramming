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

void solve(){

    string s;
    cin >> s;

    string ans = "";

    for(char k = '0'; k <= '9'; k++){
        string a = "";
        string b = "";

        int cnt = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == k) cnt++;
        }

        int j = 0;
        while(cnt){
            if(s[j] == k){
                ans += s[j];
                cnt--;
            }
            else{
                s[j]++;
                b += min(s[j], '9');
            }
            j++;
        }
        while(j < s.size()){
            a += s[j];
            j++;
        }

        sort(b.begin(), b.end());

/*

    a: 2 8 5
    b: 3 4 9 9

    c: 2 3 4 8 5 

    a => unsortable
    b => sortable

    2 2 2 1 2 1 2 7 8 9

    3 2 6 5 
    2 2 5 5 9

    2 4 5 7

    2 3 7 8 1 5 2
    1 1 1 1 1 2 2 9

    1 2 3 4 6 8 9
*/


        string c = "";
        int r = b.size();
        for(int i = a.size()-1; i >= 0; i--){
            int p = (int)(lower_bound(b.begin(), b.begin() + r, a[i]) - b.begin());
            for(j = r-1; j >= p; j--) c += b[j];
            c += a[i];
            r = p;
        }
        for(j = r-1; j >= 0; j--) c += b[j];

        reverse(c.begin(), c.end());
        
        s = c;
        //cout << ans << " - " << s << endl;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;

}