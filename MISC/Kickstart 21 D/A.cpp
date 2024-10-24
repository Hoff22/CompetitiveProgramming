#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(int q){
	int a[3][3];
	a[1][1] = 0;
	scanf("%d %d %d", &a[0][0], &a[0][1], &a[0][2]);
	scanf("%d %d", &a[1][0], &a[1][2]);
	scanf("%d %d %d", &a[2][0], &a[2][1], &a[2][2]);
	int ans = 0;

	if(abs(a[0][0] - a[0][2]) + min(a[0][0],a[0][2])*2 == a[0][1]*2) ans++;
	if(abs(a[0][0] - a[2][0]) + min(a[0][0],a[2][0])*2 == a[1][0]*2) ans++;
	if(abs(a[2][2] - a[0][2]) + min(a[2][2],a[0][2])*2 == a[1][2]*2) ans++;
	if(abs(a[2][2] - a[2][0]) + min(a[2][2],a[2][0])*2 == a[2][1]*2) ans++;

	map<int,int> m;

	if((a[0][0] - a[2][2])%2==0) m[abs(a[0][0] - a[2][2])/2 + min(a[0][0],a[2][2])]++;
	if((a[2][0] - a[0][2])%2==0) m[abs(a[2][0] - a[0][2])/2 + min(a[0][2],a[2][0])]++;
	if((a[0][1] - a[2][1])%2==0) m[abs(a[0][1] - a[2][1])/2 + min(a[0][1],a[2][1])]++;
	if((a[1][0] - a[1][2])%2==0) m[abs(a[1][0] - a[1][2])/2 + min(a[1][0],a[1][2])]++;

	int mx = 0;
	for(auto i : m) {
		mx = max(i.se,mx);
	}

	printf("Case #%d: %d\n", q, ans+mx);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}