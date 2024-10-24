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

	long long invs = 0;

	vector<int> v(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	vector<int> seen(n+1, 0);

	int k = 1;

	for(int i = 1; i <= n; i++){
		int cur = i;
		set<int> s;
		while(!seen[cur]){
			if(s.count(cur+1) or s.count(cur-1)){
				if(k > 0) k *= -1;
			}
			s.insert(cur);
			//printf("%d\n", cur);
			seen[cur] = 1;
			cur = v[cur];
			if(!seen[cur]) invs++;
		}
	}

	printf("%lld\n", invs+k);
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