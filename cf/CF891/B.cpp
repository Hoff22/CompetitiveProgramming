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

    reverse(s.begin(), s.end());

    int of = 0;
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '9' and of){
            s[i] = '0';
            of = 1;
            j = i;
        }
        else{
            s[i] = s[i]+of;
            if(s[i] >= '5'){
                s[i] = '0';
                of = 1;
                j = i;
            }
            else{
                of = 0;
            }
        }
        
    }

    if(of) s.push_back('1');

    for(int i = 0; i < j; i++){
        s[i] = '0';
    }

    reverse(s.begin(), s.end());
    cout << s << endl;
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