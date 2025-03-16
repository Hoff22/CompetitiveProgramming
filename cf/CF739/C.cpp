#include <bits/stdc++.h>

#define N (31623)
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

vector<int> is;

void solve(){
	int k;
	scanf("%d", &k);

	int l = 1;
	int r = 1;
	int i, j;
	i = 1;
	j = 2;
	for(int of = 1; of <= 10000; of += 2){

		l += of;

		int m = l + of-2;

		r += of+2;

		printf("%d %d %d %d\n", l, r, of, j);

		if(l <= k and k <= r){
			if(k >= m){
				i = of-2 + 1;
				j -= k - (m); 
			}
			else{
				i = k - l + 1;
			}
			break;
		}

		j++;
	}
	printf("%d %d\n", i, j);
	//printf("%d %d\n", r, c);
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
    return 0;

}