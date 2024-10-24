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

	vector<long long> a(n);
	set<long long> s;
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++){
		if(s.count(a[i])){
			printf("NO\n");
			return;
		}
		s.insert(a[i]);
	}

	for(long long k = 2; k <= 100; k++){
		vector<long long> cnt(k, 0);
		
		for(int i = 0; i < n; i++){
			cnt[a[i] % k]++;
		}

		bool good = false;
		for(long long r : cnt) if(r < 2) good = true;
		if(!good){
			printf("NO\n");
			return;
		} 
	}

	printf("YES\n");
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