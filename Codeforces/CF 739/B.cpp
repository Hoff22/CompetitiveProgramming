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
	int a,b,c;
	scanf("%d%d%d", &a, &b, &c);

	int of = abs(a-b);

	if(c > of*2 or a > of*2 or b > of*2) printf("%d\n", -1);
	else{
		if(c > of) printf("%d\n", c-of);
		else printf("%d\n", c+of);
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