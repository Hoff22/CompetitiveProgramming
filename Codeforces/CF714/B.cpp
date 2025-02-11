#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N];
int frontAND[N];
int backAND[N];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int last = a[0];
	for(int i = 0; i < n; i++){
		frontAND[i] = a[i] & last;
		last = a[i];
	}
	last = a[n-1];
	for(int i = n-1; i >= 0; i--){
		backAND[i] = a[i] & last;
		last = a[i];
	}

	int ans = 0;
	for(int i = 0; i < n-1; i++){
		if(frontAND[i] == backAND[i+1]){
			
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