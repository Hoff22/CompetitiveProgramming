#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define L 0
#define R 1

using namespace std;

char s[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 0 ; i < n; i++){
		scanf(" %c", &s[i]);
	}

	int ts = 0;
	int ms = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'T') ts++;
		else ms++;

		if(ms > ts){
			printf("NO\n");
			return;
		}
	}

	ts = ms = 0;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == 'T') ts++;
		else ms++;

		if(ms > ts){
			printf("NO\n");
			return;
		}
	}

	if(ts == ms*2){
		printf("YES\n");
	}
	else{
		printf("NO\n");
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