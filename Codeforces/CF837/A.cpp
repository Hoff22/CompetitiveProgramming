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
	map<int, int> cnt;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}

	sort(a.begin(), a.end());

	if(a[0] == a[n-1]){
		printf("%lld\n", 1ll * cnt[a[0]] * (cnt[a[n-1]] - 1));
	}
	else{
		printf("%lld\n", 1ll * cnt[a[0]] * cnt[a[n-1]] * 2);
	}
}

/*
	1 2
	1 3
	2 1
	2 3
	3 1
	3 2
	

*/

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