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

vector<long long> p2;

void solve(){
	int n;
	scanf("%d", &n);

	vector<pair<int,long long>> ans;

	for(int i = 0; i < n; i++){
		long long x;
		scanf("%lld", &x);

		for(int j = 0; j < p2.size(); j++){
			if(p2[j] > x){

				ans.push_back({i+1, p2[j] - x});

				break;
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for(auto i : ans){
		printf("%d %lld\n", i.fi,i.se);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    long long p = 1;

    while(p <= 2000000000){
    	p2.push_back(p);
    	p *= 2;
    }

	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}