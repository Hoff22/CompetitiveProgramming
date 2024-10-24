#include <bits/stdc++.h>

#define N 500
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

int a[N+1][N+1];

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			scanf(" %c", &c);

			if(c == '#') a[i][j] = 1;
		}
	}

	if(n < 3 and m < 3){
		printf("0\n");
		return 0;
	}

	if(n < 3 and m >= 3){
		int cnt1 = 0;
		for(int j = 1; j < m-1; j++){
			cnt1 += !(a[0][j] or a[1][j]);
		}
		printf("%d\n", cnt1);
	}
	else if(m < 3 and n >= 3){
		int cnt1 = 0;
		for(int i = 1; i < n-1; i++){
			cnt1 += !(a[i][0] or a[i][1]);
		}
		printf("%d\n", cnt1);
	}
	else{
		int cnt = 0;
		int good = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i == 0 and j == 0) continue;
				if(i == n-1 and j == 0) continue;
				if(i == n-1 and j == m-1) continue;
				if(i == 0 and j == m-1) continue;

				if(i > 0 and i < n-1 and j > 0 and j < m-1){
					cnt += (a[i][j] == 0);
				}
				else{
					if(a[i][j]) good = 1;
				}
			}
		}
		printf("%d\n", cnt + (good == 0));
	}


    return 0;

}