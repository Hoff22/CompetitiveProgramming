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

map<vector<int>, int> s;
int last = 0;

int step(vector<int>& a, int t){
    if(t>3) return 0;

    int n = a.size();

    if(s.size() != last){
        cout << s.size() << endl;
        last = s.size();
    } 

    for(int i = 0; i < n-1; i++){
        int ls = i+1;
        for(int m1 = 0; m1 < (1<<n); m1++){
            if(__builtin_popcount(m1) != ls) continue;
            int li = 0;
            int ri = ls;
            vector<int> b;
            for(int j = 0; j < n; j++){
                if((m1>>j)&1) b.push_back(a[li++]);
                else b.push_back(a[ri++]);
            }
            if(s.count(b)){
                s[b] = min(s[b], t);
            }
            else s[b] = t;
            step(b, t+1);
        }
    }
    return 0;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    //vector<int> a = {1,2,3,4,5};
    
    step(a, 1);

    // for(auto [b,t] : s){
    //     cout << t << ": ";
    //     for(int j : b) cout << j << " ";
    //     cout << endl;
    // }

    cout << s.size() << endl;

    return 0;
}

/*

cout << i << " " << j << ": " << endl;
cout << "   ";
for(int k = 0; k < n; k++) cout << ((m1>>k) & 1) << " ";
cout << endl;
cout << "   ";
for(int k = 0; k < n; k++) cout << ((m2>>k) & 1) << " ";
cout << endl;
cout << "   ";
for(int k : c) cout << k << " ";
cout << endl;
cout << "!!!!" << endl;
break;

*/