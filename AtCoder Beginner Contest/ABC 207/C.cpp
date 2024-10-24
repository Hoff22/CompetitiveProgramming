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

//map<int,int> reach;
vector<pair<int,int>> l;
vector<pair<int,int>> r;

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int t;
		int x, y;
		scanf("%d %d %d",&t, &x, &y);

		if(t == 1){
			l.push_back({x,0});
			r.push_back({y,0});
		}
		if(t == 2){
			l.push_back({x,0});
			r.push_back({y,1});
		}
		if(t == 3){
			l.push_back({x,1});
			r.push_back({y,0});
		}
		if(t == 4){
			l.push_back({x,1});
			r.push_back({y,1});
		}

	}

	long long ans = 0;

	//for(int i = 0; i < n; i++) printf("%lf %lf\n", v[i].first, v[i].second);

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(r[i].first < l[j].first) continue; 
			if(l[i].first > r[j].first) continue;
			if(r[i].first == l[j].first and (r[i].second or l[j].second)) continue;
			if(l[i].first == r[j].first and (l[i].second or r[j].second)) continue;
			ans++;
		}
	}

	printf("%lld\n", ans);

    return 0;

}