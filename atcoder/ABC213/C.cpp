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

map<pair<int,int>,int> rows;
map<pair<int,int>,int> cols;

int main(){
	
	int n;
	scanf("%*d %*d %d", &n);

	for(int i = 1; i <= n; i++){
		int x, y;

		scanf("%d %d", &x, &y);
		rows[{x,y}] = i;
		cols[{y,x}] = i;
	}

	map<int, pair<int,int>> ans;

	int lastX = 0;
	int i = 0;
	for(auto c : rows){
		if(c.fi.fi != lastX) i++;
		ans[c.se].fi = i;
		lastX = c.fi.fi;
	}

	int lastY = 0;
	int j = 0;
	for(auto c : cols){
		if(c.fi.fi != lastY) j++;
		ans[c.se].se = j;
		lastY = c.fi.fi;
	}

	for(auto c : ans){
		printf("%d %d\n", c.se.fi, c.se.se);
	}

    return 0;

}