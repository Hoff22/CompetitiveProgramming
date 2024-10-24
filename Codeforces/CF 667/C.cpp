#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	for(int i = (b-a); i >= 1; i--){
		int c = (b-a)/i;
		for(int j = 1; j <= a; j++){
			vector<int> v;
			int ia = -1;
			int ib = -1;
			v.push_back(j);
			if(j == a) ia = 1;
			//printf("%d ", v[0]);
			for(int k = 1; k < n; k++){
				v.push_back(v[k-1] + c);
				//printf("%d ", v[k]);
				if(v[k] == a) ia = k;
				if(v[k] == b) ib = k;
			}
			//printf("\n");

			if(ia != -1 and ib != -1){
				for(int k : v){
					printf("%d ", k);
				}
				printf("\n");
				return;
			}
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