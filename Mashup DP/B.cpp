#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n, k;
	set<char> allow;
	scanf("%d %d", &n, &k);

	char s[N];
	for(int i = 0; i < n; i++){
		scanf(" %c", &s[i]);
	}

	for(int i = 0; i < k; i++){
		char x;
		scanf(" %c", &x);
		allow.insert(x);
	}
	long long ans = 0;
	int last = -1;
	for(int i = 0; i < n; i++){
		if(allow.count(s[i])){
			ans += (i - last);
		}
		else{
			last = i;
		}
	}

	printf("%lld\n", ans);
}

int main(){
	
		solve();
	
    return 0;

}