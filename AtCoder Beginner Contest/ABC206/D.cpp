#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int v[N+1];
int m[N+1];

int realValue(int x){
	if(m[x] == x) return x;
	return m[x] = realValue(m[x]);
}

// 1 2 3 4 5
//         3
//     2
//         2

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= N; i++) m[i] = i;

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	int cnt = 0;
	for(int i = 1; i <= n/2; i++){
		int esq = realValue(v[i]);
		int dir = realValue(v[n+1-i]);
		if(esq != dir){
			cnt++;
			m[esq] = dir;
		}
	}

	printf("%d\n", cnt);

    return 0;

}