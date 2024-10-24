#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int main(){
	
	int n;
	vector<int> l;
	vector<int> r;

	scanf("%d", &n);

	vector<pair<int,int>> rgs(n);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &rgs[i].fi, &rgs[i].se);
		rgs[i].se--;
	}

	sort(rgs.begin(), rgs.end());

	int i = rgs[0].fi;
	int j = rgs[0].se;
	for(int k = 1; k < n; k++){
		if(rgs[k].fi <= j){
			j = max(rgs[k].se, j);
		}
		else{
			l.push_back(i);
			r.push_back(j);
			i = rgs[k].fi;
			j = rgs[k].se;
		}
	}
	l.push_back(i);
	r.push_back(j); // eca


	int ans = 0;
	for(int k = 0; k < l.size(); k++){
		ans = max(ans, r[k]/5 - (l[k]-1)/5 + (l[k] == 0));
	}

	printf("%d\n", ans);

    return 0;
}