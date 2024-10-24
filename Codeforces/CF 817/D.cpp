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

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		if(c == 'L') a[i] = 0;
		else a[i] = 1;
	}

	vector<int> ks(n);

	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(!a[i]){
			ans += i;
			ks[i] = (n-i-1) - i; 
		}
		else{
			ans += (n - i - 1);
			ks[i] = i - (n-i-1); 
		}
	}

	sort(ks.begin(), ks.end());
	reverse(ks.begin(), ks.end());

	for(int i = 0; i < n; i++){
		if(ks[i] > 0)ans += ks[i];
		printf("%lld ", ans);
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