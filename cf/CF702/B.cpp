#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;	

int c[3];

void solve(){
	int n;
	scanf("%d", &n);

	c[0] = c[1] = c[2] = 0;
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		c[x % 3]++;
	}

	int goal = n/3;
	int ans = 0;
	
	while(c[0] != goal or c[1] != goal or c[2] != goal){
		for(int i = 0; i < 3; i++){
			if(c[i] > goal){
				c[i]--;
				c[(i+1) % 3]++;
				ans++;
			}
		}
	}

	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}