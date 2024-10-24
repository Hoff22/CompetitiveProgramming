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
	
	vector<pair<long long, long long>> v;

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		long long x, p;

		scanf("%lld %lld", &x, &p);

		v.push_back({p, x});
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());


	int i = 0;
	int j = n-1;
	long long cnt = 0;
	long long ans = 0;

	while(i <= j){
		if(v[j].first <= cnt){
			ans += 1 * v[j].second;
			cnt += v[j].second;
			j--;
		}
		else{
			long long r = min(v[i].second, v[j].first - cnt);
			ans += 2 * r;
			v[i].second -= r;
			cnt += r;
			if(!v[i].second) i++;	
		}
		//printf("%d %d\n", i, j);
	}

	printf("%lld\n", ans);
	

    return 0;

}