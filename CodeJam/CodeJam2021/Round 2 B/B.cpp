#include <bits/stdc++.h>

#define N 20
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int cnt[N+1];
int n, a, b;

int go(vector<int> v, int cur){

	if(cur == 0){
		return 1;
	}

	int good = 1;
	for(int i = 1; i <= n; i++){
		if(v[i] < cnt[i]){
			good = 0;
			break;
		}
	}

	if(good) return 0;

	v[cur]--;
	v[cur-a]++;
	v[cur-b]++;

	return go(v, cur-a) * go(v, cur-b);
}

void solve(int q){
	scanf("%d%d%d", &n, &a, &b);

	for(int i = 1; i <= n; i++){
		scanf("%d", &cnt[i]);
	}

	int ans = -1;
	for(int i = n+1; i <= 1000; i++){
		vector<int> v(1000, 0);
		v[i]++;
		if(go(v, i) == 0){
			ans = i;
			break;
		}
	}
	
	printf("Case #%d: %d\n",q, ans);
}

/*

	    5
	  /   \
   5-A     5-B
  /   \
5-2*A 5-A-B
*/

int main(){
	
	int t;
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}