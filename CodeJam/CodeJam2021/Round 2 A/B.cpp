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

long long n;
vector<int> v;

long long go(long long i, long long esq, long long dir){
	if(i >= n){
		if(esq == dir) return esq;
		else return 0;
	}

	return max(go(i+1, esq + v[i], dir), go(i+1, esq, dir*v[i]));
}

void solve(int q){
	int m;
	long long ans;
	scanf("%d", &m);
	n = 0;
	v.clear();
	for(int i = 0; i < m; i++){
		int p, x;
		scanf("%d %d", &p, &x);

		while(x--){
			v.push_back(p);
			n++;
		}
	}

	ans = go(0, 0, 1);

	printf("Case #%d: %lld\n",q, ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}