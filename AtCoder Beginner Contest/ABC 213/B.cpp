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


	int n;
	scanf("%d", &n);

	vector<pair<int,int>> v;

	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);

		v.push_back({x,i});
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	printf("%d\n", v[1].se);
	
    return 0;

}