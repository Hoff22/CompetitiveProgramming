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
	vector<int> a(n+1);

	long long sum = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	int b = 0;
	int k = 0;
	for(int i = 1; i <= n; i++){
		b += a[i] - (sum/n);
		if(a[i] > sum/n) k++;
	}

	if(b == 0) printf("%d\n", k);
	else printf("-1\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}