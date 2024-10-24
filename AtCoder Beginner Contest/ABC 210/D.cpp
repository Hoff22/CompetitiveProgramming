#include <bits/stdc++.h>

#define N 1000
#define MAX 5000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

long long h,w,c;
long long a[N+2][N+2];
long long lastP[N+2][N+2];
long long lastR[N+2][N+2];
// n^2 * log_2(MAX)

int main(){
	
	scanf("%lld %lld %lld", &h, &w, &c);

	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			scanf("%lld", &a[i][j]);
		}
	}
	long long ans = INFll;

	memset(lastP, 0x3f, sizeof(lastP));
	memset(lastR, 0x3f, sizeof(lastR));

	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			lastP[i][j] = min(lastP[i-1][j], lastP[i][j-1]);
			ans = min(ans, lastP[i][j] + (a[i][j] + c*(i+j)) );
			lastP[i][j] = min(lastP[i][j], a[i][j] + c*(-i-j));
		}
	}

	for(int i = 1; i <= h; i++){
		for(int j = w; j >= 1; j--){
			lastR[i][j] = min(lastR[i-1][j], lastR[i][j+1]);
			ans = min(ans, lastR[i][j] + (a[i][j] + c*(i-j)) );
			lastR[i][j] = min(lastR[i][j], a[i][j] + c*(-i+j));
		}
	}

	printf("%lld\n", ans);

    return 0;
}



// p = a[i1][j1] + a[i2][j2] + c*(i2-i1 + j1-j2);
// p = a[i1][j1] + a[i2][j2] + ci2 -ci1 -cj2 + cj1;
// p = (a[i1][j1] - ci1 + cj1) + (a[i2][j2] + ci2 - cj2)
 

//    i              j
// a  1  7  7  9  9  6  3  7  7  8  6  4
//    0  0  0  0  0  0                  