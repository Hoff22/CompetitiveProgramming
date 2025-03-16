#include <bits/stdc++.h>

#define N 10
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long choose[N+1][N+1];

void pascal(){
   for(int i = 0; i <= N; i++){
      choose[i][0] = 1;
   }
   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= i; j++){
         choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) /*% MOD*/;
      }
   }
}

long long facts[N+1];

void factInit(){
	facts[0] = 1;
	for(int i = 1; i <= N; i++){
		facts[i] = facts[i-1] * i;
	}
}

long long p(int a, int b){
	long long r = 1;
	while(b--){
		r *= a;
	}
	return r;
}

int main(){
	
	int x = 0;
	int y = 0;

	pascal();
	factInit();

	for(int i = 0; i < 10; i++){
		char c;
		scanf("%c", &c);
		if(c == '?') x++;
		if(c == 'o') y++;
	}

	if(y > 4 or (y+x) < 1) printf("%d\n", 0);
	else{
		int ans = p(x+y, 4-y) * facts[y] * choose[4][4-y];
		//int ans = facts[y] * choose[x][4-y] * facts[4-y] * choose[4][4-y];
		//ans *= 24;
//1 2 3 4
		printf("%d\n", ans);
	}
	// 0 1 2 3
	// ? 3 4 5
    return 0;

}