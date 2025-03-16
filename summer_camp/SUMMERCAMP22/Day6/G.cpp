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

int a[N+2];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", (a+i));
	}

	a[0] = INF;
	a[n+1] = INF;

	int l, r;

	int minPref = 0;
	int minSuf = 0;
	for(l = 1; l <= n; l++){
		if(a[l] <= a[l-1]) minPref = a[l];
		else break;
	}
	for(r = n; r >= 1; r--){
		if(a[r] <= a[r+1]) minSuf = a[r];
		else break;
	}

	if(r - l < 2){
		printf("YES\n");
		return;
	}

	int allowL[N+1];
	int allowR[N+1];

	memset(allowL, INF, sizeof(allowL));
	memset(allowR, INF, sizeof(allowR));
	
	for(int i = l; i <= r; i++){
		allowL[i] = min(allowL[i-1], a[i]);
		allowL[i] = min(allowL[i], minPref);
	}
	for(int i = r; i >= l; i--){
		allowR[i] = min(allowR[i+1], a[i]);
		allowR[i] = min(allowR[i], minSuf);
	}

	


}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}