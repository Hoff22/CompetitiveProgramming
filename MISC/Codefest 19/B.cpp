#include <bits/stdc++.h>

#define N 2000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int a[N+1];
map<int,int> freq;

bool good(){
	for(auto i : freq){
		if(i.se > 1) return false;
	}
	return true;
}

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", a+i);
		freq[a[i]]++;
	}

	if(good()){
		printf("0\n");
		return;
	}

	int ans = INF;
	int i = 1;
	for(int j = 1; j <= n; j++){
		freq[a[j]]--;
		while(good()){
			ans = min(ans, j-i+1);
			freq[a[i]]++;
			i++;
		}
	}

	printf("%d\n", ans);
}

int main(){
	solve();
    return 0;

}