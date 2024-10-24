#include <bits/stdc++.h>

#define MAX 10000000
#define E 0.0000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
#define pi 3.1415926535897932384626433

using namespace std;

long double h, R, da, dw;

long double cm(long double x){
	long double air = (h-x)*da;
	long double wat = x*dw;

	return ((wat * x) + (air * (h+x))) / (wat+air);
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> h >> R >> da >> dw;

	h *= MAX;

	long double ans = 0;
	long double l = 0;
	long double r = h;
	cout << fixed << setprecision(18);

	long double e = 10;

	while(r-l >= 1){
		long double m1 = (r+l) / 2;
		long double m2 = (r+l) / 2 + e;

		if(cm(m1) <= cm(m2)){
			ans = m1;
			r = m2-e;
		}
		else{
			ans = m2;
			l = m1+e;
		}
	}

	cout << fixed << setprecision(18) << (long double)ans / MAX << endl;
}