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

map<int,int> id;
vector<int> v;
long long ans[N+1];

int main(){
	
	long long n, k;
	scanf("%lld %lld", &n, &k);

	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
		id[x] = i;
	}

	long long offset = k / n;
	
	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++){
		ans[id[v[i]]] = offset + (i < k%n);
	}

	for(int i = 1; i <= n; i++){
		printf("%lld\n", ans[i]);
	}
	

    return 0;

}