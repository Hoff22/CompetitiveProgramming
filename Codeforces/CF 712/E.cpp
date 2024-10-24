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

int main(){
	
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> v;
	for(int i = 1; i <= n; i++){
		int x, c;
		scanf("%d %d", &x, &c);
		v.push_back(make_pair(x, c));
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	long long ans = 0;
	for(int i = 0; i < n-1; i++){
		ans += max(c[v[i+1].second], v[i].first - v[i+1].first);
		//printf("%d - %d: %d\n",v[i].first, v[i+1].first, max(c[v[i+1].second], v[i].first - v[i+1].first));
	}
	ans += max(c[v[0].second], v[n-1].first - v[0].first);
	//printf("%d - %d: %d\n",v[n-1].first, v[0].first, max(c[v[0].second], v[n-1].first - v[0].first));

	printf("%lld\n", ans);

    return 0;

}
/*
8 4  0 4
7 1  1
4 2  3
3 0  1
2 3  3
0 1  2


*/