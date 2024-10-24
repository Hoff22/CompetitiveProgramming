#include <bits/stdc++.h>

#define N 200000
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

void solve(){
	int n;
	scanf("%d", &n);

	int k = n/2 - 2;

	int a = 1;
	int b = -2;

	if(n == 3){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	if(n%2 == 0){
		for(int i = 0; i < n; i++){
			if(i%2){
				printf("-1 ");
			}
			else{
				printf("1 ");
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(i%2){
				printf("%d ", b-k);
			}
			else{
				printf("%d ", a+k);
			}
		}
	}

	printf("\n");

}



/*

 1 -2 1 -2 1 == -1


a + b == b + c == c + d == d + e

a == c

b == d

c == e

-------

a == e

a + b == a + b + c + d + e

1 -1 1 -1 1

2 -1  2  -1  2


8 -6   


*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}