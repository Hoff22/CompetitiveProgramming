#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
typedef long long ll;

#define eps 0.00000001

void solve(){
    int n, m;
    cin >> n >> m;

    long long a = 0, b = 0, c = 0;

    for(int i = 0; i < m; i++){
    	long long x, y, _a, _b, _c;
    	cin >> x >> y >> _a >> _b >> _c;

    	a += _a;
    	b += _b;
    	c += _c;
    }

    cout << fixed << setprecision(18);

    long double l = 0;
    long double r = 10;
    long double ans = 0;

    while(l+eps <= r){
    	long double m1 = (r + l) / 2;
    	long double m2 = m1 + eps;

    	cout << l << " " << r << " | " << m1 << " " << m2 << endl;
    	cout << "  " << a*(m1*m1) + b*m1 + c << " " << a*(m2*m2) + b*m2 + c << endl;

    	if(a*(m1*m1) + b*m1 + c - eps >= a*(m2*m2) + b*m2 + c){
    		l = m2;
    		ans = m2;
    	}
    	else{
    		r = m1;
    		ans = m1;
    	}
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; n =1;
    
    for(int i = 0; i < n; ++i){
        solve();
    }
    
    return 0;
}