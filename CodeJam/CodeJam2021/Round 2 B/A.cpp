#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

using namespace std;

long long t[3];

void solve(int q){
	scanf("%lld %lld %lld", &t[0], &t[1], &t[2]);
 
	// 1h = 3600000000000 ns
	// 

	long long h,m,s,n;
	h = m = s = n = 0;

	int good = 0;
	for(int i = 0; i < 3; i++){
		h = t[i] / 3600000000000;
		m = (t[i]*12) % (3600000000000*12);
		s = (t[i]*720) % (3600000000000*12);

		if(t[(i+1)%3] == m and t[(i+2)%3] == s){
			good = 1;
			m = t[(i+1)%3]/(60000000000*12);
			s = t[(i+2)%3]/(60000000000*12);
			break;
		}
		if(t[(i+2)%3] == m and t[(i+1)%3] == s){
			good = 1;
			m = t[(i+2)%3]/(60000000000*12);
			s = t[(i+1)%3]/(60000000000*12);
			break;
		}
	}

	if(good){
		printf("Case #%d: %lld %lld %lld %lld\n",q, h, m, s, n);
	}
}

int main(){
	
	int q;
	scanf("%d", &q);
	
	for (int i = 1; i <= q; i++){
		solve(i);
	}
    return 0;

}