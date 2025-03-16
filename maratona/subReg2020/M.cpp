#include <bits/stdc++.h>

#define N 200000
#define MAX 10000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

long long a[N+1];
int n, c, t;

bool check(long long m){

	long long used = 1;
	long long cur = 0;
	for(int i = 0; i < n; i++){
		if(cur + a[i] <= m * t){
			cur += a[i];
		}
		else{
			used++;
			cur = a[i];
		}
		if(cur > m*t) return false;
	}

	return(used <= c);
}

int main(){
	
	scanf("%d %d %d", &n, &c, &t);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	long long l = 0;
	long long r = MAX + 1;

	while(l < r){
		long long m = l + (r - l) /2;

		if(check(m)){
			r = m;
		}
		else{
			l = m+1;
		}
	}

	printf("%lld\n", l);

    return 0;

}