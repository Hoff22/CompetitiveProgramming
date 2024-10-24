#include <bits/stdc++.h>

#define N 60
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

int a[N+1];
int n;

void go(){
	scanf("%d", &n);

	long long ans = 0;
	int zeros = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 1) ans++;
		if(a[i] == 0) zeros++;		
	}

	ans <<= zeros;

	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		go();
	}
    return 0;

}