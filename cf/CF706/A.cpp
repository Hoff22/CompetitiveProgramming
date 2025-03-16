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
	int n, k;
	cin >> n >> k;



	string s;
	cin >> s;

	if(k == 0){
		printf("YES\n");
		return;
	}

	int i;
	for(i = 1; i <= k; i++){
		if(s[i-1] != s[n-i] or i-1 == n-i-1){
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");

}

int main(){
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}
    return 0;

}