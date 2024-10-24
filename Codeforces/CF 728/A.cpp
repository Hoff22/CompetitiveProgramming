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

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> v;
	for(int i = 1; i <= n; i++) v.push_back(i);

	for(int i = 0; i < n-1; i+=2){
		swap(v[i], v[i+1]);
	}
	if(n%2) swap(v[n-2],v[n-1]);

	for(int i = 0; i < n; i++) printf("%d ", v[i]);
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