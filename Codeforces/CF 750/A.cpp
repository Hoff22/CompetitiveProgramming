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
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	int dif = 0;
	if(c%2){
		if(b%2){
			a--;
			b--;
		}
		else{
			a--;
			b-=2;
		}
	}
	if(b%2){
		dif = 2;
		if(a){
			a--;
			dif--;
		}
		if(a){
			a--;
			dif--;
		}
	}
	if(a%2){
		dif = 1;
	}

	printf("%d\n", dif);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}