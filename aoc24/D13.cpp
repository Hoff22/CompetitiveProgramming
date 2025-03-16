// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll ax, ay, bx, by;
ll X, Y;

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return true;
    }

   	// printf("0\n");

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return false;
}

bool find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy, ll &lx, ll &rx) {
    ll x, y, g;
    if (find_any_solution(a, b, c, x, y, g)){
        return 0;
    }

    // printf("1\n");

    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx){
        shift_solution(x, y, a, b, sign_b);
    }
    if (x > maxx){
        return 0;
    }

	// printf("2\n");

    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx){
        shift_solution(x, y, a, b, -sign_b);
    }
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny){
        shift_solution(x, y, a, b, -sign_a);
    }
    if (y > maxy){
        return 0;
    }

    // printf("3\n");

    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy){
        shift_solution(x, y, a, b, sign_a);
    }
    ll rx2 = x;

    if (lx2 > rx2){
        swap(lx2, rx2);
    }
    lx = max(lx1, lx2);
    rx = min(rx1, rx2);

    // printf("%lld %lld %lld %lld\n", lx1, rx1, lx2, rx2);

    if (lx > rx){
        return false;
    }
    
    return true;
}


bool smal_a_resX(ll lb, ll& a, ll&b){
	if(find_all_solutions(ax, bx, X, lb, 10000000000000000, 0, 10000000000000000, a, b)){
		// b = (X - (a * ax)) / bx;
		return true;
	}
	return  false;
}

bool smal_a_resY(ll lb, ll& a, ll&b){
	if(find_all_solutions(ay, by, Y, lb, 10000000000000000, 0, 10000000000000000, a, b)){
		return true;
	}
	return  false;
}

void solve(){
	ll ans = 0;

	while(scanf(" Button A: X+%lld, Y+%lld", &ax, &ay) != EOF){
		scanf(" Button B: X+%lld, Y+%lld", &bx, &by);
		scanf(" Prize: X=%lld, Y=%lld", &X, &Y);


		// if(X % __gcd(ax,bx) != 0 or Y % __gcd(ay,by) != 0) continue;

		ll k,o,p,q;

		if(!smal_a_resX(0, k,o) or !smal_a_resY(0, p,q)){
			continue;
		}

		if(o < q){
			swap(ax,ay);
			swap(bx,by);
		}

		printf("%lld %lld %lld %lld %lld %lld\n", ax, ay, bx, by, X, Y);
		ll l = 0;
		ll r = 10000000000000000;
		ll res = 0;

		while(l < r){
			ll m = l + (r-l)/2;

			if(!smal_a_resX(m, k,o)){
				r = m-1;
				continue;
			}
			if(!smal_a_resY(m, p,q)){
				r = m-1;
				continue;
			}

			ll hlX = (X - (k * ax)) / bx;
			ll hrX = (X - (o * ax)) / bx;

			ll hlY = (Y - (p * ay)) / by;
			ll hrY = (Y - (q * ay)) / by;

			if((hlX > hlY) == (hrX > hrY)){
				r = m-1;
			}
			else{
				res = k;
				l = m+1;
			}

			printf("%lld >\n %lld %lld\n %lld %lld\n", m, k, hlX, p, hlY);
		}

		smal_a_resX(res, k, o);
		smal_a_resY(res, p, q);
		ll hlX = (X - (k * ax)) / bx;
		ll hlY = (Y - (p * ay)) / by;

		if(k != p or hlX != hlY) continue;


		printf("%lld %lld\n", k, hlX);
	}

	printf("%lld\n", ans);
}

int main(){
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
    return 0;
}