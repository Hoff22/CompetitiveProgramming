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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
   	int n, m;
   	cin >> n >> m;

   	vector<string> s(n+1);
   	for(int i = 0; i < n; i++){
   		cin >> s[i];
   	}

   	long long ans = -1;

   	for(char c = '0'; c <= '9'; c++){

   		int good2 = 1;
   		vector<pair<long long,long long>> ps;
   		for(long long i = 0; i < n; i++){
   			int good = 0;
   			for(long long j = 0; j < m; j++){
   				if(s[i][j] == c){
   					ps.push_back({j,i});
   					good = 1;
   				}
   			}
   			if(!good) good2 = 0;
   			if(!good2) break;
   		}

   		if(!good2) continue;

   		sort(ps.begin(), ps.end());
   		map<long long, int> seen;
   		map<int,long long> use;

   		for(auto [p, i] : ps){
   			while(seen.count(p) and use[seen[p]] == p) p += m;
   			seen[p] = i;
   			if(use.count(i) == 0) use[i] = p;
   			use[i] = min(use[i], p);
   		}

   		long long cur = 0;
   		for(auto [i, p] : use) cur = max(cur, p);

   		if(ans == -1) ans = cur;
   		ans = min(ans, cur);
   	}
   	

   	cout << ans << endl;

    return 0;

}