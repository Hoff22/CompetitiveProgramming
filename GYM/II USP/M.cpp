#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

char a[N*N];
int n, m;

int solve(int i, int sum){

	if(i == n*m){
		return sum;
	}

	if(a[i] == 'L'){
		return max(solve(i+1, 0), sum);
	}

	if(a[i] == '.') return solve(i+1, sum+1);
	
	return solve(i+1, sum);

}

int main(){
	

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i % 2){
				scanf(" %c", &a[((i+1)*n - 1) - j]);
			}
			else{
				scanf(" %c", &a[i*n + j]);
			}
		}
	}

	printf("%d\n", solve(0, 0));
	

    return 0;

}