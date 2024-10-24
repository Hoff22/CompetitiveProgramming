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

    for(int i = 1; i <= 9; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    int cnt = 0;

    vector<int> h = {1,2,3};
    for(int j = 0; j < 3; j++){
        set<int> s;
        s.insert(a[h[0]+j*3]);
        s.insert(a[h[1]+j*3]);
        s.insert(a[h[2]+j*3]);
        //cout << a[h[0]+j*3] << " " << a[h[1]+j*3] << " " << a[h[2]+j*3] << endl;
        if(s.size() == 2){
          //  cout << "h" << j << endl; 
            cnt++;
        }
    }
    vector<int> v = {1,4,7};
    for(int j = 0; j < 3; j++){
        set<int> s;
        s.insert(a[v[0]+j]);
        s.insert(a[v[1]+j]);
        s.insert(a[v[2]+j]);
        if(s.size() == 2){
            //cout << "v " << j << endl; 
            cnt++;
        }
    }
    vector<int> d1 = {1,5,9};
    vector<int> d2 = {3,5,7};
    
    set<int> s;
    s.insert(a[d1[0]]);
    s.insert(a[d1[1]]);
    s.insert(a[d1[2]]);
    if(s.size() == 2) cnt++;
    s.clear();
    s.insert(a[d2[0]]);
    s.insert(a[d2[1]]);
    s.insert(a[d2[2]]);
    if(s.size() == 2) cnt++;

    //cout << cnt << endl;

    cout <<fixed << setprecision(18) << pow(2.0/3.0, cnt) << endl;

    return 0;

}