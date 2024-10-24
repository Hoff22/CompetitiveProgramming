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

int sumDig(int x){
	int sum = 0;
	while(x){
		sum += (x%10);
		x /= 10;
	}
	return sum;
}

void solve(){
	int n;
	scanf("%d", &n);

	if(n%2){
		int a = n/2;
		int b = n/2+1;

		int i = 1;
		while(sumDig(a)-1 > sumDig(b)){
			if((a/i)%10 == 0 or (b/i)%10 == 9){
				i*=10;
				continue;
			}

			a -= i;
			b += i;
		}
		i = 1;
		while(sumDig(b)-1 > sumDig(a)){
			if((b/i)%10 == 0 or (a/i)%10 == 9){
				i*=10;
				continue;
			}

			b -= i;
			a += i;
		}

		printf("%d %d\n", a, b);
	}
	else{
		printf("%d %d\n", n/2, n/2);
	}
}

/*

93457299
139
140 + = 279

135 = 9
144 = 9 


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