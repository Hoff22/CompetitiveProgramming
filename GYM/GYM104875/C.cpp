#include <bits/stdc++.h>

#define MAX 10000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
constexpr long double sq2 = 1.41421356237309504880168872420969807856967187537694807317667973799;

using namespace std;

long long cal(long double rad){
	long long side = (long long)floor(rad/sq2);

	long long ans = side*side;

	for(long long i = side+1; i <= floor(rad); i++){
		long long l = 0;
		long long r = side;
		long long a = 0;
		while(l <= r){
			long long m = (l+r) / 2;

			if(i*i + m*m <= rad*rad){
				a = m;
				l = m+1;
			}
			else{
				r = m-1;
			}
		}
		// cout << i << " " << a << endl;
		ans += a*2;
	}
	// cout << endl;

	return ans*4;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long s;
	cin >> s;

	long double l = 0.0;
	long double r = 200000.0;

	while(r-l > E){
		long double m = (r+l) / 2;

		if(cal(m) <= s){
			l = m+E;
		}
		else{
			r = m-E;
		}
	}

	cout << fixed << setprecision(18) << l << endl;

	return 0;
} 