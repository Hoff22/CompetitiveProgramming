#include <bits/stdc++.h>

#define N 300000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1];
int c[N+1];
int n;


void solve(int q){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int dif = 0;
	c[0] = 1;
	for(int i = 1; i < n; i++){
		if(a[i] - a[i-1] == dif){
			c[i] = c[i-1]+1;
		}
		else{
			c[i] = 2;
			dif = a[i] - a[i-1];
		}
	}

	int ans = 0;
	for(int i = 1; i < n; i++){
		int mx = 0;
		if(c[i] > c[i-1]){
			mx = c[i];
		}
		else{
			dif = a[i] - a[i-1];
			
			for(int j = 1; j < n; j++){

			}
		}
		ans = max(mx, ans);
	}

	printf("Case #%d: %d\n", q, ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}