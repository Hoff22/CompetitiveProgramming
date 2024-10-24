#include <bits/stdc++.h>

#define N 1000001
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

    map<string, int> cnt;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        for(int j = 0; j < n; j++){
            if(s[j] == '*'){

                for(char c = 'a'; c <= 'z'; c++){
                    cnt[s.substr(0,j) + c + s.substr(j+1, m-j)]++;
                }

                break;
            }
        }
    }

    string ans;
    int v = 0;
    for(auto i : cnt){
        if(i.se > v){
            ans = i.fi;
            v = i.se;
        }
    }

    cout << ans << " " << v << endl;

    return 0;

}