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

void solve(){
	int n, w;
	map<int,int> m;
	vector<int> v;
	scanf("%d %d", &n, &w);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(m[x] == 0) v.push_back(x);
		m[x]++;
	}

	sort(v.begin(), v.end());

	reverse(v.begin(), v.end());

	int ans = 0;
	while(v.size()){
		int len = w;
		for(int i = 0; i < v.size(); i++){
			int hw = min(len/v[i], m[v[i]]);

			len -= hw * v[i];
			m[v[i]] -= hw;

			if(m[v[i]] == 0){
				v.erase(v.begin()+i);
				i--;
			}
		}
		ans++;
	}

	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}