#include <bits/stdc++.h>

#define N 100000
#define MAX 10000000000
#define E 0.00000001
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

long long adj[4][4] = {{0, 1, 1, 1} , {1, 0, 1, 1} , {1, 1, 0, 1} , {1, 1, 1, 0}};
//int identidade[4][4] = {{1, 0, 0, 0} , {0, 1, 0, 0} , {0, 0, 1, 0} , {0, 0, 0, 1}};

void mul4x4(long long a[4][4], long long b[4][4], long long ans[4][4]){
	long long a2[4][4];
	long long b2[4][4];

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			a2[i][j] = a[i][j];
			b2[i][j] = b[i][j];
			ans[i][j] = 0;
		}
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				ans[i][j] += a2[i][k] * b2[k][j]; 
			}
			ans[i][j] %= MOD;
		}
	}
}

int main(){
	
	int n;
	scanf("%d", &n);

	long long ans[4][4] = {{1, 0, 0, 0} , {0, 1, 0, 0} , {0, 0, 1, 0} , {0, 0, 0, 1}}; 

	while(n > 0){
		if(n & 1){
			mul4x4(ans, adj, ans);
		}

		mul4x4(adj, adj, adj);

		n >>= 1;
	}


	printf("%lld\n", ans[3][3]);

	return 0;
}