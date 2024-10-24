#include <bits/stdc++.h>
 
#define fi first
#define se second
#define MOD 1000000007
#define N 1000000
 
using namespace std;
 
typedef long long ll;

template <typename T, int mod = 1000000007>
struct mat2x2{
    T v[2][2];

    mat2x2(T a00 = 1, T a01 = 0, T a10 = 0, T a11 = 1){
        v[0][0] = a00;
        v[0][1] = a01;
        v[1][0] = a10;
        v[1][1] = a11;
    }

    const T* operator[](const int idx) const{
        return v[idx];
    }

    T* operator[](const int idx){
        return v[idx];
    }

    mat2x2<T,mod>& operator+=(const mat2x2<T,mod>& a){
        for(int r = 0; r < 2; r++){
            for(int c = 0; c < 2; c++){
                v[r][c] = (v[r][c] + (a[r][c] % mod)) % mod;
            }
        }
        return *this;
    }

    mat2x2<T,mod>& operator*=(const mat2x2<T,mod>& a){
        mat2x2<T,mod> res(0,0,0,0);
        for(int r = 0; r < 2; r++){
            for(int c = 0; c < 2; c++){
                for(int i = 0; i < 2; i++){
                    T nv = ((v[r][i] % mod) * (a[i][c] % mod)) % mod;
                    res[r][c] = ((res[r][c] % mod) + nv) % mod;
                }
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                v[i][j] = (res[i][j] % mod);
            }
        }
        return *this;
    }

    friend mat2x2<T,mod> operator*(mat2x2<T,mod> a, const mat2x2<T,mod> b){
        a *= b;
        return a;
    }

    friend ostream& operator<<(ostream& os, mat2x2<T,mod> a){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                os << a[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }

};

typedef mat2x2<long long, MOD> ll2;

ll2 fast_pow(ll2 a, long long b){
    ll2 res;
    while(b>0){
        if(b&1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve(){
    long long n;
    cin >> n;

    if(n == 0){
        cout << 0 << endl;
        return;
    }

    ll2 a(1,1,1,0);
    a = fast_pow(a, n-2);

    cout << (a[0][0] + a[0][1]) % MOD << endl;
}
 
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}