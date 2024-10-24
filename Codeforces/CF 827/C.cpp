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
int a[8][8];

void solve(){

	memset(a, 0, sizeof(a));

	for(int i = 0 ; i < 8; i++){
		for(int j = 0; j < 8; j++){
			char c;
			scanf(" %c", &c);

			if(c == 'B') a[i][j] = 2;
			if(c == 'R') a[i][j] = 1;
		}
	}

	for(int i = 0 ; i < 8; i++){

		int good = 1;
		for(int j = 0; j < 8; j++){
			if(a[i][j] == 2) good = 0;
		}

		if(good){
			printf("R\n");
			return;
		}
	}

	for(int j = 0 ; j < 8; j++){

		int good = 1;
		for(int i = 0; i < 8; i++){
			if(a[i][j] == 1) good = 0;
		}

		if(good){
			printf("B\n");
			return;
		}
	}


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