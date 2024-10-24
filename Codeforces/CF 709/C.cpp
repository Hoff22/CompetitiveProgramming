#include <bits/stdc++.h>
 
#define N 100000
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
	int n, m;
	scanf("%d %d", &n, &m);
	set<int> d[N];
	map<int,int> cnt;
	vector<int> ans;
 
	for(int i = 0; i < m; i++){
		int k;
		scanf("%d", &k);
 
		for(int j = 0; j < k; j++){
			int x;
			scanf("%d", &x);
			d[i].insert(x);
			if(!j){
				cnt[x]++;
				ans.push_back(x);
			}
		}
	}
 
	int bad = 0;
	for(auto f : cnt){
		if(f.second > (m+1)/2){
			bad = f.first;
			break;
		}
	}
 
	int i = 0;
	while(cnt[bad] > (m+1)/2 and i < m){
 
		if(d[i].size() <= 1 or d[i].count(bad) == 0) {
			i++;
			continue;
		}
		int mn = bad;
		for(auto f : d[i]){
			if(cnt[f] <= cnt[mn]){
				mn = f;
			}
		}
		if(cnt[mn] < (m+1)/2){
			cnt[mn]++;
			cnt[bad]--;
			ans.erase(ans.begin()+i);
			ans.insert(ans.begin()+i, mn);
		}
 
		i++;
	}
 
	if(cnt[bad] > (m+1)/2 or ans.size() != m){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int j = 0; j < m; j++){
		printf("%d ", ans[j]);
	}
	printf("\n");
 
}
 
int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;
 
}