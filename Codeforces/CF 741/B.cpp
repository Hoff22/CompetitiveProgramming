#include <bits/stdc++.h>

#define N 50
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

char s[N+1];

bool isP(int n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return 0;
	}
	return 1;
}



void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %c", &s[i]);
	}

	for(int i = 0; i < n; i++){
		int x = s[i] - '0';

		if(!isP(x)){
			printf("%d\n%d\n", 1, x);
			return;
		}
	}

	for(int i = 0; i < n; i++){
		
		for(int j = i+1; j < n; j++){
			int x = s[i] - '0';
			int y = s[j] - '0';
			int r = x*10 + y;

			if(!isP(r)){
				printf("%d\n%d\n", 2, r);
				return;
			}
		}
	}

	printf("%d\n", n);
	for(int i = 0; i < n; i++){
		printf("%c", s[i]);
	}
	printf("\n");
}
// ELMBRA MUDA O nnN

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
    return 0;

}