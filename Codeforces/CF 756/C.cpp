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

	deque<int> d;
	vector<int> v(n+1);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	if(v[1] != n and v[n] != n){
		printf("-1\n");
		return;
	}

	int l, r;
	l = 1;
	r = n;

	while(l <= r){

		if(v[l] > v[r]){
			d.push_front(v[l]);
			l++;
		}
		else{
			d.push_back(v[r]);
			r--;
		}

	}

	while(!d.empty()){
		printf("%d ", d.front());
		d.pop_front();
	}
	printf("\n");


}

/*

	1 3 5 4 2
	1 1 1 1 1
    1 2 2 2 2	

	1 3 2 6 5 4

	2 3 1 4 5

	2 >

	3 >

	1 <

	4 > *

	1 4 2 3
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