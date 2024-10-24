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

	if(n&1){
		printf("-1\n");
		return;
	}

	int last = 0;
	int t = n;
	while(t){
		if(t & 1){
			if(last){
				printf("-1\n");
				return;
			}
			last = 1;
		}
		else last = 0;

		t >>= 1;
	}

	printf("%d %d\n", (n>>1), (n>>1)^n);
}


/*

  1 0 0 1 0 0  = 2a
  0 1 0 0 1 0  = a
  1 1 0 1 1 0  = b


  1 1 0 1 1 0
  0 1 0 0 1 0
             = 100100

1 0 0 1 0 0 0


  1 0 0 1 0
  0 1 0 0 1 a 
  1 1 0 1 1 b


  1 1 0
    1 1  a


   1 0 1 
   0 1 0 a
   1 1 0 b






  1 0 0 1 0 0
    0 1 0 0 1



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