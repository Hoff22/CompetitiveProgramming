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

    vector<int> order = {1,2,3,4,5,6,7,8,9};

    vector<int> a(10, 0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i*3+j+1];
        }
    }

    // for(int i = 1; i <= 9; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int cnt = 0;

    do{
        //for(int i : order) cout << i << " ";
        //cout << endl;
        int bad = 0;
        vector<bool> s(10,0);
        for(int i = 0; i < 9; i++){
            s[order[i]] = 1;
            if(order[i] == 3 or order[i] == 6 or order[i] == 9){
                if(s[order[i]-1] and s[order[i]-2]){
                    if(a[order[i]-1] == a[order[i]-2]) bad++;
                }
            }
            if(order[i] == 2 or order[i] == 5 or order[i] == 8){
                if(s[order[i]-1] and s[order[i]+1]){
                    if(a[order[i]-1] == a[order[i]+1]) bad++;
                }
            }
            if(order[i] == 1 or order[i] == 4 or order[i] == 7){
                if(s[order[i]+1] and s[order[i]+2]){
                    if(a[order[i]+1] == a[order[i]+2]) bad++;
                }
            }

            if(order[i] == 7 or order[i] == 8 or order[i] == 9){
                if(s[order[i]-3] and s[order[i]-6]){
                    if(a[order[i]-3] == a[order[i]-6]) bad++;
                }
            }
            if(order[i] == 4 or order[i] == 5 or order[i] == 6){
                if(s[order[i]-3] and s[order[i]+3]){
                    if(a[order[i]-3] == a[order[i]+3]) bad++;
                }
            }
            if(order[i] == 1 or order[i] == 2 or order[i] == 3){
                if(s[order[i]+3] and s[order[i]+6]){
                    if(a[order[i]+3] == a[order[i]+6]) bad++;
                }
            }

            if(order[i] == 9 and s[order[i]-4] and s[order[i]-8]){
                if(a[order[i]-4] == a[order[i]-8]) bad++;
            }
            if(order[i] == 5 and s[order[i]-4] and s[order[i]+4]){
                if(a[order[i]-4] == a[order[i]+4]) bad++;
            }
            if(order[i] == 1 and s[order[i]+4] and s[order[i]+8]){
                if(a[order[i]+4] == a[order[i]+8]) bad++;
            }

            if(order[i] == 7 and s[order[i]-2] and s[order[i]-4]){
                if(a[order[i]-2] == a[order[i]-4]) bad++;
            }
            if(order[i] == 5 and s[order[i]-2] and s[order[i]+2]){
                if(a[order[i]-2] == a[order[i]+2]) bad++;
            }
            if(order[i] == 3 and s[order[i]+2] and s[order[i]+4]){
                if(a[order[i]+2] == a[order[i]+4]) bad++;
            }
        }
        if(bad==0) cnt++;

    }while(next_permutation(order.begin(), order.end()));

    //cout << cnt << endl;

    cout <<fixed << setprecision(18) << 1.0*cnt/362880.0 << endl;

    return 0;

}