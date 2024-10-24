#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    map<string, int> cnt[2];

    int cur = 0;

	string f;
    while(cin >> f){
        if(f[0] == '-'){
            cur = 1;
        }
        else if(f[0] == '='){
            break;
        }
        else{
            int t1 = stoi(f);
            int t2;
            string name;
            cin >> t2 >> name;

            if(cur == 1){
                if(cnt[0].count(name) == 0){
                    cnt[0][name] = 0;
                }
            }
            cnt[cur][name] += (t2-t1);
        }
    }

    int nodif = 1;

    for(auto [name, v1] : cnt[0]){
        if(cnt[1][name] == v1) continue;
        nodif = 0;
        if(cnt[1][name] > v1){
            cout << name << " +" << cnt[1][name]-v1 << endl;
        }
        else {
            cout << name << " -" << v1-cnt[1][name] << endl;
        }
    }

    if(nodif){
        cout << "No differences found." << endl;
    }

    return 0;

}