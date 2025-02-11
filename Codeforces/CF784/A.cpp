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

	if(n < 1400){
		printf("Division 4\n");
	}
	else if(n < 1600){
		printf("Division 3\n");
	}else if(n < 1900){
		printf("Division 2\n");
	}else{
		printf("Division 1\n");
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