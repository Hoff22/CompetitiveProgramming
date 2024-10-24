#include <bits/stdc++.h>

#define N 200000
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

void solve(){
	int n;
	scanf("%d", &n);
	int a[N+1];
	int good = 1;
	for(int i = 0; i < n; i++) scanf("%d", (a+i));
	int last;
	for(int i = 1; i < n; i+=2){
		if(i == 1) last = a[i];
		if(a[i] % 2 != last % 2) good = 0;
		last = a[i];
	}
	if(!good){
		printf("NO\n");
		return;
	}
	for(int i = 0; i < n; i+=2){
		if(i == 0) last = a[i];
		if(a[i] % 2 != last % 2) good = 0;
		last = a[i];
	}
	if(!good){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}