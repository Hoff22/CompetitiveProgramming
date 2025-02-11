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

int cnt[26];

void solve(){
	int n;
	scanf("%d", &n);

	memset(cnt, 0, sizeof(cnt));
	char last = -1;
	for(int i = 0; i < n; i++){
		char x;
		scanf(" %c", &x);
		if(last != x){
			cnt[(x-'A')]++;
		}
		last = x;
	}

	for(int i = 0; i < 26; i++){
		if(cnt[i] > 1){
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}