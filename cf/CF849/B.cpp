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
	int x = 0;
	int y = 0;

	int good = 0;
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		if(c == 'U'){
			y++;
		}
		if(c == 'D'){
			y--;
		}
		if(c=='R'){
			x++;
		}
		if(c=='L'){
			x--;
		}

		if(x == 1 and y == 1) good = 1;
	}	

	if(good) printf("YES\n");
	else printf("NO\n");

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