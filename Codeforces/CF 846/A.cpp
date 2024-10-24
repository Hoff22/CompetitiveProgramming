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

	int odds = 0;
	int even = 0;

	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i]%2) odds++;
		else even++;
	}

	if(odds == 0 or (odds == 2 and even == 1)){
		printf("NO\n");
		return;
	}

	printf("YES\n");

	if(odds >= 3){
		int c = 0;
		for(int i = 1; i <= n; i++){
			if(a[i]%2){
				printf("%d ", i);
				c++;
			}
			if(c == 3) break;
		}
	}
	else{
		int c1 = 0;
		int c2 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i]%2 and c1 < 1){
				printf("%d ", i);
				c1++;
			}
			if(a[i]%2 == 0 and c2 < 2){
				printf("%d ", i);
				c2++;
			}
		}
	}
	printf("\n");
}

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