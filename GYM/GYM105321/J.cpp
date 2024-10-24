#include <bits/stdc++.h>

#define N 200000
#define T 400
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

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n,x; cin >> n >> x;
    vector<int> a(n);
    int h = 0;
    set<int> s;
    vector<int> l, r;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        s.insert(a[i]);
        if(a[i]*2 == x){
            h++;
        }
    }


    if(2*h > n+1){
        cout << "*\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(a[i]*2 == x) continue;
        if(s.count(x-a[i])){
            if(x-a[i] > a[i]) l.push_back(a[i]);
            else r.push_back(a[i]);
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i]*2 == x) continue;
        if(!s.count(x-a[i])){
            l.push_back(a[i]);
        }
    }

    // for(int j : l) cout << j << " ";
    // cout << endl;
    // for(int j : r) cout << j << " ";
    // cout << endl;

    if(r.empty()){
        for(int i : l){
            if(h){
                cout << x/2 << " ";
                h--;
            }
            cout << i << " ";
        }
        if(h){
            cout << x/2 << " ";
            h--;
        }
        cout << endl;
        return 0;
    }

    if(l.back() + r[0] == x and h < l.size()+1){

        if(h == 0){
            cout << "*\n";
            return 0;
        }

        // . L.  L.  L.  R R

        // . L . L . L . L 


        // h = 3
        // L L L L L R R R
        // 0 1 2 3 4
        // l.size() - i == h

        // L L L h L h L h R R R

        for(int i = 0; i < l.size(); i++){
            cout << l[i] << " ";
            if(l.size()-i == h){
                cout << x/2 << " ";
                h--;
            }
        }

        for(int i : r){
            cout << i << " ";
        }
        cout << endl;

        return 0;
    }

    for(int i : l){
        if(h){
            cout << x/2 << " ";
            h--;
        }
        cout << i << " ";
    }
    for(int i : r){
        if(h){
            cout << x/2 << " ";
            h--;
        }
        cout << i << " ";
    }
    if(h){
        cout << x/2 << " ";
        h--;
    }
    cout << endl;

    return 0;

}