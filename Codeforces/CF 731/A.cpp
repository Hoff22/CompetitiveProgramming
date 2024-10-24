#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int xa,ya;
	int xb,yb;
	int xf,yf;

	scanf(" %d %d", &xa, &ya);
	scanf(" %d %d", &xb, &yb);
	scanf(" %d %d", &xf, &yf);

	int m = 0;
	if(xf >= min(xa, xb) and xf <= max(xa,xb) and yf >= min(ya, yb) and yf <= max(ya,yb)){
		m = 2;
	}

	if(xa == xb){
		if(xf == xa) printf("%d\n", abs(ya-yb) + m);
		else printf("%d\n", abs(ya-yb));
	}
	else if(ya == yb){
		if(yf == ya) printf("%d\n", abs(xa-xb) + m);
		else printf("%d\n", abs(xa-xb));
	}
	else{
		printf("%d\n", abs(xa-xb) + abs(ya-yb));
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