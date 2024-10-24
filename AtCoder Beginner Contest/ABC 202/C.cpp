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

map<int,int> a;
map<int,vector<int>> b;
map<int,int> c;

int main(){

	int n;
	scanf("%d", &n);

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		a[x]++;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		b[x].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		c[x]++;
	}

	long long ans = 0;
	for(auto i : a){
		x = i.first;
		if(!b.count(x)) continue;

		for(int j = 0; j < b[x].size(); j++){
			ans += c[b[x][j]] * i.second;
		}
	}

	printf("%lld\n", ans);


	
    return 0;
}