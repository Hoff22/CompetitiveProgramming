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

char s[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %c", &s[i]);
	}

	int ans = INF;
	for(int c = 'a'; c <= 'z'; c++){
		int cur = 0;
		int i, j;
		i = 0;
		j = n-1;
		while(i < j){
			if((s[i] == c) and (s[i] != s[j])){
				i++;
				cur++;
			}
			else if(s[j] == c and s[i] != s[j]){
				j--;
				cur++;
			}
			else if(s[i] != s[j]){
				cur = INF;
				break;
			}
			else{
				i++;
				j--;
			}
		}
		//printf("%c, %d\n", c, cur);
		ans = min(ans, cur);
	}

	if(ans >= INF){
		printf("-1\n");
	}
	else printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}