#include <bits/stdc++.h>

#define N 10000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){

	int n, l, r, s;
	scanf("%d %d %d %d", &n, &l, &r, &s);

	vector<int> v(n+1,0);

	if(s < (r-l+1)*(r-l+2)/2){
		printf("-1\n");
		return;
	}

	int cur = 1;
	for(int i = l; i <= r; i++){	
		v[i] = cur;
		s -= cur;
		cur++;
	}

	int right = r;
	int mx = n;
	while(s and l <= right){
		v[right]++;
		s--;
		if(v[right] == mx and s){
			mx--;
			right--;
		}
	}
	// 1 2 0 - 2
	// 1 3 0 - 1
	// 2 3 0 - 0
	if(s == 0){
		set<int> seen;
		for(int i = 1; i <= n; i++) seen.insert(i);
		for(int i = l; i <= r; i++) seen.erase(v[i]);
		for(int i = 1; i <= n; i++){
			if(l > i or i > r){
				v[i] = *seen.begin();
				seen.erase(v[i]);
			}
		}
		for(int i = 1; i <= n; i++){
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	else{
		printf("-1\n");
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