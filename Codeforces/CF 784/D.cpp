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

	int R = 0;
	int B = 0;
	int good = 1;
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		if(c == 'W'){
			if((!R and B) or (R and !B)){
				good = 0;
			}
			R = 0;
			B = 0;
		}
		if(c == 'R') R++;
		if(c == 'B') B++;
	}
	if((!R and B) or (R and !B)){
			good = 0;
	}
	if(good) printf("YES\n");
	else printf("NO\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}