#include <bits/stdc++.h>

#define N 100000
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
int n;
// m = c - that[i];
// c = that[i] - that[i-1]
void solve(){
	scanf("%d", &n);

	int mx = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}

	int c = -1;
	for(int i = 2; i <= n; i++){
		if(a[i] >= a[i-1]){
			if(c == -1) c = a[i] - a[i-1];
			else if(c != a[i] - a[i-1]){
				c = -2;
				break;
			}
		}
	}

	int lastI, lastLastI;
	lastI = lastLastI = -1;

	for(int i = 2; i <= n; i++){
		if(a[i] < a[i-1]){
			if(lastI == -1){
				lastI = a[i];
				lastLastI = a[i-1];
			}
			else if(a[i] - lastI != a[i-1] - lastLastI){
				lastI = -2;
				break;
			}
			if(a[i] > lastI){
				lastI = a[i];
				lastLastI = a[i-1];
			}
		}
	}

	if(c == -2 or lastI == -2){
		printf("-1\n");
	}
	else if(c == -1 or lastI == -1){
		printf("0\n");
	}
	else{
		if(c > lastI and lastLastI+(c - lastI) > mx){
			printf("%d %d\n", lastLastI+(c - lastI), c);
		}
		else{
			printf("-1\n");
		}
	}

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}