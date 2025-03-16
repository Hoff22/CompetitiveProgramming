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

int n;
vector<double> p; 
vector<double> g; 

void solve(){
	scanf("%d", &n);

	p.assign(n, 0.0);
	g.assign(n, 0.0);

	for(int i = 0; i < n; i++){
		scanf("%lf", &p[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%lf", &g[i]);
	}

	double mxt = *max_element(g.begin(), g.end());

	vector<pair<double,double>> v;
	for(int i = 0; i < n; i++){
		v.push_back({p[i],g[i]});
	}

	sort(v.begin(), v.end());

	double l = *min_element(p.begin(), p.end());
	double t = mxt;

	for(int i = 0; i < n-1; i++){
		
		t = min(t, mxt - v[i].se);
		double d = min(t, v[i+1].fi - v[i].fi);

		l = v[i].fi + d;

		t -= d; 

		if(t == 0.0) break;
	}

	double r = *max_element(p.begin(), p.end());
	t = mxt;

	for(int i = n-1; i >= 1; i--){
		
		t = min(t, mxt - v[i].se);
		double d = min(t, v[i].fi - v[i-1].fi);

		r = max(v[i].fi - d, l);

		t -= d; 

		if(t == 0.0) break;
	}

	//printf("%lf %lf\n", l ,r);

	printf("%.18lf\n", l + (r - l) / 2);

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}