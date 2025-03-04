#include<bits/stdc++.h>

#define N 100000
#define X 0
#define Y 1
#define INF 0x3f3f3f3f

using namespace std;

int pos[N+1][2];

int main(){

	int T;
	scanf("%d", &T);

	while(T--){
		int n, m, count = 0;
		scanf("%d%d", &n, &m);

		for(int i = 0; i < m; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			if(x == y){
				count++;
			}
		}

		if(count){
			printf("%d\n", m - count);
		}
		else{
			if(m == 1){
				printf("1\n");
			}
			else{
				printf("%d\n", m + 1);
			}
		}
	}


	return 0;
}