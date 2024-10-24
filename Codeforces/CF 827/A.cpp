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
	scanf("%d %d %d", &a, &b, &c);

	if(a + b == c){
		printf("YES\n");
		return;
	}
	if(a + c == b){
		printf("YES\n");
		return;
	}
	if(b + c == a){
		printf("YES\n");
		return;		
	}

	printf("NO\n");	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}