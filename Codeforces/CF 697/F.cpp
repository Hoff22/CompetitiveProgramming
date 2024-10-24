#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;


void solve(){
	char a[N+1][N+1];
	char b[N+1][N+1];

	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf(" %c", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf(" %c", &b[i][j]);
		}
	}

	for(int i = 1; i <= n; i++){
		if(a[i][1] != b[i][1]){
			for(int k = 1; k <= n; k++){
				if(a[i][k] == '1') a[i][k] = '0';
				else a[i][k] = '1';
			}
		}
	}

	for(int j = 2; j <= n; j++){
		for(int i = 1; i <= n; i++){
			if((a[i][j] == b[i][j]) != (a[1][j] == b[1][j])){
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}

int main(){

	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}