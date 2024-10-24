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

int p2[10000+4];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n, q;
    cin >> n >> q;

    vector<tuple<int,int,int>> qs;

    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }


    for(int i = 1; i <= 10000; i *= 2){
        p2[i] = 1;
    }

    for(int i = 0; i < q; i++){
        int l , r;
        cin >> l >> r;
        qs.push_back({l,r,i});
    }

    sort(qs.begin(), qs.end(), [&](tuple<int,int,int> i, tuple<int,int,int> j){
        int l1, l2, r1, r2, i1, i2;
        tie(l1,r1,i1) = i;
        tie(l2,r2,i2) = j;
        if(l1/T != l2/T) return l1 < l2;
        if((l1 / T) % 2) return r1 > r2;
        return r1 < r2;
    });

    vector<char> ans(q);

    ll sumA = 0;
    ll sumB = 0;
    ll ones = 0;

    int cl = 0;
    int cr = -1;

    auto add = [&](int i){
        if(a[i] == 1) ones++;
        else if(a[i] % 2) sumB += a[i];
        else if(p2[a[i]]) sumA += a[i];
    };

    auto sub = [&](int i){
        if(a[i] == 1) ones--;
        else if(a[i] % 2) sumB -= a[i];
        else if(p2[a[i]]) sumA -= a[i];
    };

    for(auto [l,r,i] : qs){
        while(cr < r){
            cr++;
            add(cr);
        }
        while(cr > r){
            sub(cr);
            cr--;
        }
        while(cl < l){
            sub(cl);
            cl++;
        }
        while(cl > l){
            cl--;
            add(cl);
        }

        if(sumA + ((ones + 1) / 2) > sumB + (ones/2)){
            ans[i] = 'A';
        }
        else if(sumA + ((ones + 1) / 2) < sumB + (ones/2)){
            ans[i] = 'B';
        }
        else{
            ans[i] = 'E';
        }
    }

    for(char i : ans) cout << i << endl;

    return 0;

}