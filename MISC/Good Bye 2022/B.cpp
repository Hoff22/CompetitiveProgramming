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
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> ans(n+1, 0);

	set<int> p;
	for(int i = 1; i <= n; i++) p.insert(i);

	for(int i = k; i <= n; i+=k){
		ans[i] = *p.begin();
		p.erase(ans[i]);
	}

	set<int,greater<int>> p2;

	while(p.size()){
		int x = *p.begin();
		p2.insert(x);
		p.erase(x);
	}

	for(int i = 1; i <= n; i++){
		if(!ans[i]){
			ans[i] = *p2.begin();
			p2.erase(ans[i]);
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d%c", ans[i], " \n"[i==n]);
	}
}

/*

 1 2 3 4 5 6
       
 5 1 4 2 3 

 5 4 3 1 2

 6 6


 5 3 1 4 2 
 6 5 5 


5 1 4 


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