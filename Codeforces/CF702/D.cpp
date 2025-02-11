#include <bits/stdc++.h>

#define N 100
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

#define LEFT(x) (x * 2)
#define RIGHT(x) (x * 2 + 1)

using namespace std;

vector<int> a;
int n;

int depth(int i){
	int ans = 0;

	int l = 0;
	int r = n;
	while(l < r){
		int mx = i;
		for(int j = l; j < r; j++){
			if(a[j] > a[mx]) mx = j;
		}

		if(i == mx) break;
		if(i < mx){
			r = mx;
		}
		else{
			l = mx+1;
		}
		ans++;
	}
	return ans;
}

void solve(){
	scanf("%d", &n);

	a.clear();
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		a.push_back(x);
	}

	for(int i = 0; i < n; i++){
		printf("%d ", depth(i));
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}