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

	if(n%2 == 0){
		printf("No\n");
		return;
	}
	else{
		printf("YES\n");

		int k = n*2;
		for(int i = 1; i <= n; i+= 2){
			printf("%d %d\n", i, k);
			k--;
		}

		int q = n-1;
		for(int i = n+1; i <= k; i++){
			printf("%d %d\n", q, i);
			q-=2;
		}
	}
}

/*

1 2 = 3
3 4 = 7

1 3 = 4
2 4 = 6

1 4 = 5
2 3 = 5

1 2

1 2 3 4 5 6 7 8 9 | 10 11 12 13 14 15 16 17 18

1 											18 = 19
    3 									 17    = 20
        5							  16       = 21
            7 					   15          = 22
                9               14             = 23
              8     10                         = 18
          6            11                      = 17
      4                   12                   = 16
  2                          13                = 15        


a + b = c + d - 1 = e + f - 2



1 2 3 4 5 6 | 7 8 9 10 11 12

1 12 = 13
3 11 = 14
5 10 = 15
6 7  = 1


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