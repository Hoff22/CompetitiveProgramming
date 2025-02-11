#include <bits/stdc++.h>

#define N 200
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int used[N*N+1];
int n;

void move(int c, int i, int j){
	printf("%d %d %d\n", c, i, j);
	fflush(stdout);
}

int main(){
	
	scanf("%d", &n);
	
	int idx[4];
	idx[1] = 0;
	idx[2] = 1;
	idx[3] = 0;

	for(int k = 0; k < n*n; k++){
		int a;
		scanf("%d", &a);

		if(a != 1){
			while((used[idx[1]] or ((idx[1]/n+1) + (idx[1]%n+1)) % 2 == 1) and idx[1] < n*n){
				idx[1]++;
			}
			if(idx[1]+1 <= n*n){
				move(1, idx[1]/n + 1, idx[1]%n + 1);
				used[idx[1]] = 1;
				continue;
			}
		}
		if(a != 2){
			while((used[idx[2]] or ((idx[2]/n+1) + (idx[2]%n+1)) % 2 == 0) and idx[2] < n*n){
				idx[2]++;
			}
			if(idx[2]+1 <= n*n){
				move(2, idx[2]/n + 1, idx[2]%n + 1);
				used[idx[2]] = 1;
				continue;
			}
		}
		while(used[idx[3]] and idx[3] < n*n){
			idx[3]++;
		}
		if(idx[3]+1 <= n*n){
			move(3, idx[3]/n + 1, idx[3]%n + 1);
			used[idx[3]] = 1;
		}
	}

    return 0;

}