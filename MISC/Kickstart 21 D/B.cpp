#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(int t){
	int n;
	long long c;
	long long ans = 0;
	scanf("%d %lld", &n, &c);

	long long vl[N+1];
	long long vr[N+1];

	vector<pair<long long,long long>> v;
	
	for(int i = 0; i < n; i++){
		long long l, r;
		scanf("%lld %lld", &l, &r);
		v.push_back({l,r});
	}

	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		vl[i] = v[i].fi;
		vr[i] = v[i].se;
	}

	queue<pair<long long,long long>> q;

	long long l, r;
	int i = 1;
	int j = 1;

	l = vl[0];
	r = vr[0];
	while(i < n or j < n){
		while(vr[j] > vl[i]){
			i++;
			if(i==n) break;
		}
		while(j < i){
			r = max(r, vr[j]);
			j++;
			if(j==n) break;
		}
		if(vl[i] > r or (i == n and j == n)){
			q.push({l, r});
			l = vl[i];
			r = vr[j];
		}
		else j--; // - - - - - -
	}
	vector<pair<long long,long long>> a;

	while(c and !q.empty()){
		pair<long long, long long> cur = q.front();
		q.pop();
		long long m = cur.fi + (cur.se - cur.fi+1)/2;
		printf("%lld\n", m);
		
		if(m - cur.fi > 1) q.push({cur.fi,m});
		else a.push_back({cur.fi,m});			
		if(cur.se - m > 1) q.push({m,cur.se});			
		else a.push_back({m,cur.se});
		c--;			
	}

	while(!q.empty()){
		a.push_back({q.front().fi, q.front().se});
		q.pop();
	}

	for(auto p : a){
		printf("%lld %lld\n", p.fi, p.se);
		for(auto b : v){
			printf("\t%lld %lld\n", b.fi, b.se);
			if(p.fi >= b.fi and p.se <= b.se) ans++;
		}
	}

	printf("Case #%d: %lld\n", t, ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}