#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n;
	priority_queue<int> miner;
	priority_queue<int> diam;
	scanf("%d", &n);

	double ans = 0;

	for(int i = 0; i < 2*n; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		if(x){
			diam.push(abs(x));
		}
		else{
			miner.push(abs(y));
		}
	}

	while(!miner.empty()){
		int m = miner.top();
		miner.pop();
		int d = diam.top();
		diam.pop();

		ans += sqrt(1.0*d*d + 1.0*m*m);
	}

	printf("%.15lf\n", ans);
	// e = sqrt((xd)^2 + (ym)^2)


}

int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
    return 0;

}